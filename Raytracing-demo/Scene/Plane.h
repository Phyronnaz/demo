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
    Color color;

    Plane(const Vector& position, const Vector& vectorx, const Vector& vectory, const Color& color);

    bool intersect(const Ray& ray, Hit& hit) const override;
};