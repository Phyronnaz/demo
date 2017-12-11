#pragma once

#include "Plane.h"

/*!
 * The TexturePlane class is a plane with a diffuse texture and a normal texture.
 */
class TexturePlane : public Plane
{
public:
    TexturePlane(const Vector& position,
                 const Vector& vector_x,
                 const Vector& vector_y,
                 char const* diffuse_filename,
                 char const* normal_filename);

protected:
    Color get_color(double x, double y) const override;

    Vector get_additional_normal(double x, double y) const override;

private:
    unsigned char* diffuse_data;
    unsigned char* normal_data;
    int diffuse_x, diffuse_y, diffuse_n;
    int normal_x, normal_y, normal_n;
};