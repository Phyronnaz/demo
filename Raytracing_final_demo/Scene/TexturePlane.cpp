#include <cmath>
#include <cassert>
#include "TexturePlane.h"
#include "stb_image.h"

TexturePlane::TexturePlane(const Vector& position,
                           const Vector& vector_x,
                           const Vector& vector_y,
                           char const* diffuse_filename,
                           char const* normal_filename)
        : Plane(position, vector_x, vector_y)
{
    diffuse_data = stbi_load(diffuse_filename, &diffuse_x, &diffuse_y, &diffuse_n, 0);
    normal_data = stbi_load(normal_filename, &normal_x, &normal_y, &normal_n, 0);
    assert(diffuse_data);
    assert(normal_data);
}

inline int mod(double x, int m)
{
    return static_cast<int>(std::fmod(std::fmod(x, m) + m, m));
}

Color TexturePlane::get_color(double x, double y) const
{
    int index = diffuse_n * (mod(x, diffuse_x) + mod(y, diffuse_y) * diffuse_x);
    return Color(diffuse_data[index],
                 diffuse_data[index + 1],
                 diffuse_data[index + 2],
                 diffuse_n > 3 ? diffuse_data[index + 3] : 0) / 255;
}

Vector TexturePlane::get_additional_normal(double x, double y) const
{
    int index = normal_n * (mod(x, normal_x) + mod(y, normal_y) * normal_x);
    return Vector(normal_data[index], normal_data[index + 1], normal_data[index + 2]).unit();
}
