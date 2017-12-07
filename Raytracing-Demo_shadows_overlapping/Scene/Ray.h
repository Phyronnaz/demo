#pragma once

#include "Vector.h"
#include "Color.h"

using namespace rt;

struct Ray
{
    Vector origin;
    Vector direction;
    Color color;

    Ray() = default;

    Ray(const Vector& origin, const Vector& direction, const Color& color)
            : origin(origin), direction(direction), color(color)
    {

    }
};