#include <cmath>
#include "Scene.h"
#include "Ray.h"
#include <deque>
#include <thread>

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"

Scene::Scene(const std::vector<Object*>& objects,
             const std::vector<Light*>& lights,
             Camera* camera,
             double width,
             double height,
             char const* filename)
        : objects(objects),
          lights(lights),
          camera(camera),
          width(width),
          height(height)
{
    diffuse_data = filename ? stbi_load(filename, &diffuse_x, &diffuse_y, &diffuse_n, 0) : nullptr;
}

void Scene::render_scene(rt::screen& screen)
{
    std::vector<rt::color> colors(static_cast<unsigned long>(screen.width() * screen.height()));
    std::deque<std::thread> threads;
    int thread_count = 5;
    for (int i = 0; i < thread_count; i++)
    {
        for (int j = 0; j < thread_count; j++)
        {
            threads.push_front(std::thread(&Scene::render_thread,
                                           this,
                                           i * screen.width() / thread_count,
                                           (i + 1) * screen.width() / thread_count,
                                           j * screen.height() / thread_count,
                                           (j + 1) * screen.height() / thread_count,
                                           screen.width(),
                                           screen.height(),
                                           std::ref(colors)));
        }
    }

    for (std::thread& t : threads)
    {
        t.join();
    }

    for (int i = 0; i < screen.width(); i++)
    {
        for (int j = 0; j < screen.height(); j++)
        {
            screen.set_pixel(i, screen.height() - j, colors[i + screen.width() * j]);
        }
    }
}

void Scene::render_thread(int starti, int endi, int startj, int endj, int screen_width, int screen_height,
                          std::vector<rt::color>& out_colors)
{
    for (int i = starti; i < endi; i++)
    {
        for (int j = startj; j < endj; j++)
        {
            double i_coeff = (i - screen_width / 2) * width / screen_width / 2;
            double j_coeff = (j - screen_height / 2) * height / screen_height / 2;

            Vector coord = camera->get_z();

            const Vector start_position(i_coeff * camera->orientation + j_coeff * camera->get_z() + camera->position);
            const Vector end_position = start_position + camera->direction * 250;

            const Vector current_position(camera->position);
            Ray ray(current_position, (end_position - current_position).unit());

            std::deque<Hit> hits;
            Vector final_direction = ray.direction;

            int gui = 0;
            while (true)
            {
                if(gui == 10)
                {
                    break;
                }
                gui++;
                double min_distance = 1e100;
                Ray new_ray = ray;
                Hit hit;
                for (Object* object : objects)
                {
                    Hit tmp_hit;
                    if(object->intersect(ray, tmp_hit))
                    {
                        double distance = (tmp_hit.hit_point - tmp_hit.ray.origin).squared_norm();
                        if(distance < min_distance)
                        {
                            min_distance = distance;
                            new_ray.direction = tmp_hit.normal;
                            new_ray.origin = tmp_hit.hit_point;
                            hit = tmp_hit;
                        }
                    }
                }
                if(hit.hit_object)
                {
                    Color color(Color::BLACK);
                    for (Light* light : lights)
                    {
                        Ray light_ray(light->position, hit.hit_point - light->position);
                        double distance_to_light = (light->position - hit.hit_point).squared_norm();
                        bool collide = false;
                        for (Object* object : objects)
                        {
                            Hit tmp_hit;
                            if(object->intersect(light_ray, tmp_hit))
                            {
                                if(distance_to_light > (light->position - tmp_hit.hit_point).squared_norm())
                                {
                                    collide = true;
                                    break;
                                }
                            }
                        }
                        if(!collide)
                        {
                            color += light->apply(hit);
                        }
                    }
                    hit.color = color;
                    hits.push_front(hit);
                    ray = Ray(hit.hit_point, (-hit.ray.direction).reflect_around_normal(hit.normal));
                }
                else
                {
                    final_direction = ray.direction;
                    break;
                }
            }

            Color prev_color;

            if(diffuse_data)
            {
                final_direction = final_direction.unit();
                long long u = (0.5 + std::atan2(final_direction.y, final_direction.x) / (2 * M_PI)) * diffuse_x;
                long long v = (0.5 - std::asin(final_direction.z) / M_PI) * diffuse_y;
                long long index = diffuse_n * (u + diffuse_x * v);

                prev_color = Color(diffuse_data[index],
                                   diffuse_data[index + 1],
                                   diffuse_data[index + 2],
                                   diffuse_n > 3 ? diffuse_data[index + 3] : 0);
            }
            else
            {
                prev_color = Color::BLACK;
            }

            while (!hits.empty())
            {
                Hit hit = hits.front();
                hits.pop_front();

                prev_color = prev_color * hit.hit_object->reflection + hit.color * (1 - hit.hit_object->reflection);
            }

            out_colors[i + screen_width * j] = prev_color;
        }
    }
}

