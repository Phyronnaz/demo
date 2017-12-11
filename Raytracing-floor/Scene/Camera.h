#pragma once

#include <iostream>
#include <cassert>

#include "Vector.h"

/*!
 * Hold informations about the camera
 */
class Camera
{
public:
    Vector position;
    Vector direction;
    Vector orientation;

    Camera(Vector position, Vector direction, Vector orientation) :
            position(position),
            direction(direction.unit()),
            orientation(orientation.unit())
    {

    }

    /*!
     * Get the up axis of this camera
     * @return Up axis
     */
    Vector get_z() const
    {
        return Vector::vectorial_product(orientation, direction);
    }
};
