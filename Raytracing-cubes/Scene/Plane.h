#pragma once

#include "Color.h"
#include "Vector.h"
#include "Hit.h"
#include "Object.h"

using namespace rt;

class Plane : public Object
{
public:
    Plane(const Vector& position, const Vector& vectorx, const Vector& vectory);

    bool intersect(const Ray& ray, Hit& hit) const override;

protected:
    virtual Color get_color(double x, double y) const = 0;
    virtual Vector get_additional_normal(double x, double y) const = 0;

private:
    Vector position;
    Vector vector_x;
    Vector vector_y;
};