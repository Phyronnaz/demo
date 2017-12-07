#pragma once

#include "../Screen/color.hpp"

struct Color
{
    unsigned char R;
    unsigned char G;
    unsigned char B;
    unsigned char A;

    static Color WHITE;
    static Color BLACK;
    static Color BLUE;
    static Color GREEN;
    static Color RED;

    /**
     * Default constructor. Builds a white color.
     */
    Color();

    /**
     * Copy constructor.
     */
    Color(const Color& c);

    /**
     * Builds a color from its red, green and blue components.
     * Alpha is set to 255.
     */
    Color(unsigned char r, unsigned char g, unsigned char b);

    /**
     * Builds a color from its red, green, blue and alpha components.
     */
    Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

    /**
     * Comparison operator.
     */
    virtual bool operator==(const Color& c) const;

    virtual Color operator*(const double& d) const;

    virtual Color operator/(const double& d) const;

    virtual Color operator+(const Color& c) const;

    /**
     * Cast operator to int.
     * Represents the color as a int, with
     * red being the most significant byte.
     */
    virtual operator int() const;

    operator rt::color() const;

    static Color add_colors(const Color& c1, const Color& c2);
};