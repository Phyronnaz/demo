#pragma once

#include "Vector.h"
#include "Color.h"
#include "Ray.h"
#include "Hit.h"

using namespace rt;

/*!
 * Base class for all objects
 */
class Object
{
public:
    double diffuse = 50.0;
    double specular = 50.0;
    double specular_exponent = 5.0;
    double reflection = 0;

    /*!
     * Check if ray intersects with this object
     * @param[in] ray The ray
     * @param[out] hit If this object is hit, will be set with hit infos
     * @return Whether this object was hit
     */
    virtual bool intersect(const Ray& ray, Hit& hit) const = 0;
};
