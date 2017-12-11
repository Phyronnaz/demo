#pragma once

#include "Color.h"
#include "Vector.h"
#include "Hit.h"
#include "Object.h"

/*!
 * Abstract class for a plane object. A plane is defined by a position and 2 vectors
 */
class Plane : public Object
{
public:
    Plane(const Vector& position, const Vector& vectorx, const Vector& vectory);

    bool intersect(const Ray& ray, Hit& hit) const override;

protected:
    /*!
     * Get the color of the plane at coordinates (x, y)
     * @param x x position
     * @param y y position
     * @return Color
     */
    virtual Color get_color(double x, double y) const = 0;

    /*!
     * Get the normal of the plane at coordinates (x, y)
     * @param x x position
     * @param y y position
     * @return Normal
     */
    virtual Vector get_additional_normal(double x, double y) const = 0;

private:
    Vector position;
    Vector vector_x;
    Vector vector_y;
};