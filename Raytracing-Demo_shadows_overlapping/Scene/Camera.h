#pragma once

#include <iostream>
#include <cassert>

#include "Vector.h"

using namespace rt;

class Camera
{

private:
    Vector position;
    Vector orientation;
    /* For simplification purposes, we consider that the camera must be horizontal, that is, the first coordinate must be 0 */

public:
    Camera() : position(300.0, 300.0, 0.0), orientation(0.0, 0.0, 1.0)
    {}

    Camera(Vector _position, Vector _orientation)
    {
        position = _position;
        Vector new_orientation = Vector(0, _orientation.y, _orientation.z);
        /*
         * The x coordinate must be zero
         * and at least one other coordinate
         * must be different from zero
         */
        assert(new_orientation.norm() != 0);
        orientation = new_orientation.unit();
    }

    Vector get_position() const
    {
        return position;
    }

    Vector get_orientation() const
    {
        return orientation;
    }

    void set_position(Vector _position)
    {
        position = _position;
    }

    void set_orientation(Vector _orientation)
    {
        Vector new_orientation = Vector(0, _orientation.y, _orientation.z);
        /*
         * The x coordinate must be zero
         * and at least one other coordinate
         * must be different from zero
         */
        assert(new_orientation.norm() != 0);
        orientation = new_orientation.unit();
    }
};
