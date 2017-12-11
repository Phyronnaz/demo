#pragma once

#include "Vector.h"
#include "Color.h"

using namespace rt;

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