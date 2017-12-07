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
            double x = i * width / screen.width() + camera->get_position().x;
            double y = camera->get_position().y;
            double z = height - j * height / screen.height() + camera->get_position().z;

            const Vector start_position(x, y, z);
            Ray ray(start_position, Vector::FORWARD, Color::BLACK);

            double min_distance = 1e100;
            Ray new_ray = ray;
            Hit new_hit;
            for (auto object : objects)
            {
                Hit hit;
                if(object->intersect(ray, hit))
                {
                    double distance = (hit.hit_point - hit.ray.origin).squared_norm();
                    if(distance < min_distance)
                    {
                        min_distance = distance;
                        new_ray.direction = hit.normal;
                        new_ray.origin = hit.hit_point;
                        new_ray.color = hit.color;
                        new_hit = hit;
                    }
                }
            }

            Color color = Color::BLACK;
            for (auto light : lights)
            {
                Ray light_ray(new_hit.hit_point, (light->position - new_hit.hit_point).unit(), Color::WHITE);
                double distance_to_light = (light->position - new_hit.hit_point).squared_norm();
                bool collide = false;
                for (auto object : objects)
                {
                    Hit hit;
                    if(object->intersect(light_ray, hit))
                    {
                        if(distance_to_light > (hit.hit_point - light->position).squared_norm())
                        {
                            collide = true;
                        }
                    }
                }
                if(!collide)
                {
                    color = color + light->apply(new_hit);
                }
            }

            screen.set_pixel(i, j, color);
        }
    }
}
