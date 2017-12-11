#include <cmath>
#include "CheckedPlane.h"

CheckedPlane::CheckedPlane(const Vector& position,
                           const Vector& x,
                           const Vector& y,
                           const Color& color1,
                           const Color& color2)
        : Plane(position, x, y), color1(color1), color2(color2)
{

}

inline int mod(double x, int m)
{
    return static_cast<int>(std::fmod(std::fmod(x, m) + m, m));
}

Color CheckedPlane::get_color(double x, double y) const
{
    if((mod(x, 100) < 50) ^ (mod(y, 100) < 50))
    {
        return color1;
    }
    else
    {
        return color2;
    }
}

Vector CheckedPlane::get_additional_normal(double x, double y) const
{
    return Vector();
}

