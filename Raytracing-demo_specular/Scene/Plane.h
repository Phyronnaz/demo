#pragma once

#include "Color.h"
#include "Vector.h"
#include "Hit.h"
#include "Object.h"

using namespace rt;

class Plane : public Object
{
public:
    Vector position;
    Vector vectorx;
    Vector vectory;

    Plane(const Vector& position, const Vector& vectorx, const Vector& vectory, const Color& color,
          double diffuse = 1, double specular = 0.5, double specular_exponent = 5.f);

    bool intersect(const Ray& ray, Hit& hit) const override;
};