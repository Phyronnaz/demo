#pragma once

#include "Vector.h"
#include "Color.h"
#include "Ray.h"
#include "Hit.h"

using namespace rt;

class Object
{
public:
    const Color color;
    const double diffuse = 50.0;
    const double specular = 50.0;
    const double specular_exponent = 5.0;

    Object(const Color& color, const double diffuse, const double specular, const double specular_exponent)
            : color(color), diffuse(diffuse), specular(specular), specular_exponent(specular_exponent)
    {}

    virtual bool intersect(const Ray& ray, Hit& hit) const = 0; /* Pure virtual method */
};
