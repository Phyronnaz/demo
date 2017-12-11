#pragma once

#include "Vector.h"
#include "Color.h"

/*!
 * A ray is defined by an origin and a direction
 */
struct Ray
{
    Vector origin;
    Vector direction;

    Ray() = default;

    Ray(const Vector& origin, const Vector& direction)
            : origin(origin), direction(direction.unit())
    {

    }
};