#pragma once

#include "Vector.h"
#include "Color.h"
#include "Ray.h"
#include "Hit.h"

using namespace rt;

class Object
{

private:
    Color col;
    double diffuse = 50.0;
    double specular = 50.0;
    double specular_exponent = 5.0;

public:
    virtual bool intersect(const Ray& ray, Hit& hit) const = 0; /* Pure virtual method */

    // Get methods
    Color get_color() const
    {
        return col;
    }

    double get_diffuse() const
    {
        return diffuse;
    }

    double get_specular() const
    {
        return specular;
    }

    double get_specular_exponent() const
    {
        return specular_exponent;
    }

    // Set methods
    void set_color(Color c)
    {
        col = c;
    }

    void set_diffuse(double diff)
    {
        diffuse = diff;
    }

    void set_specular(double spec)
    {
        specular = spec;
    }

    void set_specular_exponent(double spec_ex)
    {
        specular_exponent = spec_ex;
    }

    // General set method
    void set_appearance(Color c, double diff, double spec, double spec_ex)
    {
        col = c;
        diffuse = diff;
        specular = spec;
        specular_exponent = spec_ex;
    }
};
