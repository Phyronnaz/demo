#pragma once

#include "Vector.h"
#include "Ray.h"
#include "Color.h"

class Object;

struct Hit
{
    Vector hit_point;
    Ray ray;
    Vector normal;
    Color color;
    const Object* hit_object;

    Hit() = default;

    Hit(const Vector& hit_point, const Ray& ray, const Vector& normal, const Color& color,
        const Object* const& hit_object)
            : hit_point(hit_point), ray(ray), normal(normal), color(color), hit_object(hit_object)
    {

    }
};


