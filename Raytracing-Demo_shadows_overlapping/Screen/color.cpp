#include "color.hpp"

namespace rt {

color color::WHITE = color(255,255,255);
color color::BLACK = color(0,0,0);
color color::BLUE  = color(0,0,255);
color color::GREEN = color(0,255,0);
color color::RED   = color(255,0,0);

color::color()
{
    red = green = blue = alpha = 0;
}

color::color(const color& c)
{
    red   = c.get_red();
    green = c.get_green();
    blue  = c.get_blue();
    alpha = c.get_alpha();
}

color::color(unsigned char r, unsigned char g, unsigned char b)
{
    red   = r;
    green = g;
    blue  = b;
    alpha = 255;
}

color::color(unsigned char r, unsigned char g,
             unsigned char b, unsigned char a)
{
    red   = r;
    green = g;
    blue  = b;
    alpha = a;
}

bool color::operator ==(const color& c) const
{
    return     (c.get_red()   == get_red())
               && (c.get_green() == get_green())
               && (c.get_blue()  == get_blue())
               && (c.get_alpha() == get_alpha());
}

color::operator int() const
{
    unsigned int1 = get_red();
    unsigned int2 = (256 * int1) + get_green();
    unsigned int3 = (256 * int2) + get_blue();
    unsigned int4 = (256 * int3) + get_alpha();
    return (int) int4;

    /**
        Other possibility suggested by Matthieu Dorier:

        return (((int)get_red()) << 24) + (((int)get_green()) << 16)
                + (((int)get_blue()) << 8) + (int)get_alpha();
      */
}

}
