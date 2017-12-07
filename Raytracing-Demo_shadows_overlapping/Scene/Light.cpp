#include <cmath>
#include <algorithm>
#include "Light.h"

DirectionalLight::DirectionalLight(const Vector& normal, const double& intensity)
        : Light(Vector(1e100, 1e100, 1e100)), normal(normal), intensity(intensity)
{

}

Color DirectionalLight::apply(Hit h)
{
    double theta = std::max(0., -Vector::scalar_product(normal.unit(), h.normal));
    return h.color * (theta * intensity);
}

PointLight::PointLight(const Vector& position, const double& intensity)
        : Light(position), intensity(intensity)
{

}

Color PointLight::apply(Hit h)
{
    Vector normal = h.hit_point - position;
    double theta = std::max(0., -Vector::scalar_product(normal.unit(), h.normal));
    return h.color * (theta * intensity / normal.squared_norm());
}
