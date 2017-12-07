#pragma once


#include "Vector.h"
#include "Ray.h"
#include "Color.h"

struct Hit
{
    Vector hit_point;
    Ray ray;
    Vector normal;
    Color color;

    Hit() = default;

    Hit(const Vector& hit_point, const Ray& ray, const Vector& normal, const Color& color)
            : hit_point(hit_point), ray(ray), normal(normal), color(color)
    {

    }
};


