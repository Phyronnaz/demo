#pragma once

#include <iostream>
#include <cassert>

#include "Vector.h"

using namespace rt;

class Camera
{
public:
    Vector position;
    Vector orientation;

    Camera() : position(300.0, 300.0, 0.0), orientation(0.0, 0.0, 1.0)
    {}

    Camera(Vector position, Vector orientation) : position(position), orientation(orientation)
    {

    }
};
