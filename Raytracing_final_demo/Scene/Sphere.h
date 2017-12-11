#pragma once

#include "Vector.h"
#include "Color.h"
#include "Object.h"
#include "Ray.h"
#include "Hit.h"

/*!
 * The Sphere class defines a sphere with a center, a radius and a color.
 */
class Sphere : public Object
{
public:
    const Vector center;
    const double radius;
    const Color color;

    Sphere(const Vector& center, const double& radius, const Color& color);

    bool intersect(const Ray& ray, Hit& hit) const override;
};