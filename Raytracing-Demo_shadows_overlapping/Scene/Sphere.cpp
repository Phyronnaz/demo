#include <cmath>
#include "Sphere.h"

bool Sphere::intersect(const Ray& ray, Hit& hit) const
{
    Vector AC = ray.origin - center;
    double c = AC.squared_norm() - radius * radius;
    double b = -2 * Vector::scalar_product(AC, ray.direction);

    double delta = b * b - 4 * c;

    if(delta > 0)
    {
        double x1 = (b - std::sqrt(delta)) / 2;
        double x2 = (b + std::sqrt(delta)) / 2;
        if(x1 < x2)
        {
            hit.hit_point = ray.origin + x1 * ray.direction;
        }
        else
        {
            hit.hit_point = ray.origin + x2 * ray.direction;
        }
        hit.ray = ray;
        hit.normal = (hit.hit_point - center).unit();
        hit.color = color;
        return Vector::scalar_product(hit.hit_point - ray.origin, ray.direction) >= 0;
    }
    else
    {
        return false;
    };
}

Sphere::Sphere(const Vector& center, const double& radius, const Color& color)
        : center(center), radius(radius), color(color)
{}
