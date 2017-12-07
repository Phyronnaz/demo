#include <cmath>
#include "Scene.h"
#include "Ray.h"

Scene::Scene(const std::vector<Object*>& objects, const std::vector<Light*>& lights,
             Camera* camera, double width, double height)
        : objects(objects), lights(lights), camera(camera), width(width), height(height)
{}

void Scene::render_scene(rt::screen& screen)
{
    for (int i = 0; i < screen.width(); i++)
    {
        for (int j = 0; j < screen.height(); j++)
        {
            double x = i * width / screen.width() + camera->position.x;
            double y = camera->position.y;
            double z = height - j * height / screen.height() + camera->position.z;

            const Vector start_position(x, y, z);
            Ray ray(start_position, camera->orientation, Color::BLACK);

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
                        new_ray.color = tmp_hit.color;
                        hit = tmp_hit;
                    }
                }
            }

            Color color = Color::BLACK;
            if(hit.hit_object)
            {
                for (Light* light : lights)
                {
                    Ray light_ray(hit.hit_point, (light->position - hit.hit_point).unit(), Color::WHITE);
                    double distance_to_light = (light->position - hit.hit_point).squared_norm();
                    bool collide = false;
                    for (Object* object : objects)
                    {
                        Hit tmp_hit;
                        if(object->intersect(light_ray, tmp_hit))
                        {
                            if(distance_to_light > (tmp_hit.hit_point - light->position).squared_norm())
                            {
                                collide = true;
                            }
                        }
                    }
                    if(!collide)
                    {
                        color += light->apply(hit);
                    }
                }
            }

            screen.set_pixel(i, j, color);
        }
    }
}
