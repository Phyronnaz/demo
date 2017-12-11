#pragma once

#include "Plane.h"

/*!
 * Checked plane object
 */
class CheckedPlane : public Plane
{
public:
    CheckedPlane(const Vector& position, const Vector& x, const Vector& y, const Color& color1, const Color& color2);

protected:
    Color get_color(double x, double y) const override;

    Vector get_additional_normal(double x, double y) const override;

private:
    Color color1;
    Color color2;
};