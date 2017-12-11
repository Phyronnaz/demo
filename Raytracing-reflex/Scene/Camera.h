#pragma once

#include <iostream>
#include <cassert>

#include "Vector.h"

using namespace rt;

class Camera
{
public:
    Vector position;
    Vector direction;
    Vector orientation;

    Camera() : position(300.0, 300.0, 0.0), direction(0.0, 0.0, 1.0), orientation(0.0, 1.0, 0.0)
    {}

    Vector get_z() const
    {
        return Vector::vectorial_product(orientation, direction);
    }

    Camera(Vector position, Vector direction, Vector orientation) :
            position(position),
            direction(direction.unit()),
            orientation(orientation.unit())
    {

    }


};
