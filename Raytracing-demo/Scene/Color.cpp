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

Color::Color(unsigned char r, unsigned char g, unsigned char b) : R(r), G(g), B(b), A(255)
{}


Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a) :
        R(r), B(b), G(g), A(a)
{}

bool Color::operator==(const Color& c) const
{
    return (c.R == R) &&
           (c.G == G) &&
           (c.B == B) &&
           (c.A == A);
}

Color::operator int() const
{
    return (((int) R) << 24) + (((int) G) << 16) + (((int) B) << 8) + (int) A;
}

unsigned char clamp_to_char(double d)
{
    return (unsigned char) (d < 0 ? 0 : d > 255 ? 255 : d);
}

Color Color::operator*(const double& d) const
{
    return Color(clamp_to_char(R * d), clamp_to_char(G * d), clamp_to_char(B * d), clamp_to_char(A * d));
}

Color Color::add_colors(const Color& c1, const Color& c2)
{
    return Color(std::min(c1.R, c2.R), std::min(c1.G, c2.G), std::min(c1.B, c2.B), std::min(c1.A, c2.A));
}

Color Color::operator/(const double& d) const
{
    return Color(clamp_to_char(R / d), clamp_to_char(G / d), clamp_to_char(B / d), clamp_to_char(A / d));
}

Color Color::operator+(const Color& c) const
{
    return Color(clamp_to_char(R + c.R), clamp_to_char(G + c.G), clamp_to_char(B + c.B), clamp_to_char(A + c.A));
}

Color::operator rt::color() const
{
    return rt::color(R, G, B, A);
}
