#include <algorithm>
#include "Color.h"

Color Color::WHITE = Color(255, 255, 255);
Color Color::BLACK = Color(0, 0, 0);
Color Color::BLUE = Color(0, 0, 255);
Color Color::GREEN = Color(0, 255, 0);
Color Color::RED = Color(255, 0, 0);

Color::Color()
{
    R = G = B = A = 0;
}

Color::Color(const Color& c) : R(c.R), G(c.G), B(c.B), A(c.A)
{
}

Color::Color(double r, double g, double b) : R(r), G(g), B(b), A(255)
{}


Color::Color(double r, double g, double b, double a) :
        R(r), B(b), G(g), A(a)
{}

bool Color::operator==(const Color& c) const
{
    return (c.R == R) &&
           (c.G == G) &&
           (c.B == B) &&
           (c.A == A);
}

double clamp_to_char(double d)
{
    return (double) (d < 0 ? 0 : d > 255 ? 255 : d);
}

Color& Color::operator*=(const double& d)
{
    R = R * d;
    G = G * d;
    B = B * d;
    A = A * d;
    return *this;
}

Color& Color::operator/=(const double& d)
{
    R = R / d;
    G = G / d;
    B = B / d;
    A = A / d;
    return *this;
}

Color& Color::operator+=(const Color& c)
{
    R += c.R;
    G += c.G;
    B += c.B;
    A += c.A;
    return *this;
}

Color& Color::operator-=(const Color& c)
{
    R -= c.R;
    G -= c.G;
    B -= c.B;
    A -= c.A;
    return *this;
}

Color::operator rt::color() const
{
    return rt::color(clamp_to_char(R), clamp_to_char(G), clamp_to_char(B), clamp_to_char(A));
}

Color Color::add_colors(const Color& c1, const Color& c2)
{
    return Color(std::min(c1.R, c2.R), std::min(c1.G, c2.G), std::min(c1.B, c2.B), std::min(c1.A, c2.A));
}

Color const operator+(const Color& left, const Color& right)
{
    return Color(left) += right;
}

Color const operator-(const Color& left, const Color& right)
{
    return Color(left) -= right;
}

Color const operator*(const Color& left, const double& right)
{
    return Color(left) *= right;
}

Color const operator/(const Color& left, const double& right)
{
    return Color(left) /= right;
}