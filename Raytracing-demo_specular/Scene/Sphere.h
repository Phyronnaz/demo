#pragma once

#include "Vector.h"
#include "Color.h"
#include "Object.h"
#include "Ray.h"
#include "Hit.h"

class Sphere : public Object
{
public:
    const Vector center;
    const double radius;

    Sphere(const Vector& center, const double& radius, const Color& color,
           double diffuse = 0.5, double specular = 0.5, double specular_exponent = 5);

    bool intersect(const Ray& ray, Hit& hit) const override;
};