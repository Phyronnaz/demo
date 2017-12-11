#include <cmath>
#include <algorithm>
#include "Light.h"
#include "Object.h"

DirectionalLight::DirectionalLight(const Vector& normal, const double& intensity)
        : Light(Vector(1e100, 1e100, 1e100)), normal(normal.unit()), intensity(intensity)
{

}

Color DirectionalLight::apply(Hit h)
{
    double LdI = std::max(0., -Vector::scalar_product(normal, h.normal));
    double Ld = h.hit_object->diffuse * LdI;

    Vector H = ((position - h.hit_point) + h.ray.direction).unit();
    double LsI = std::max(0., -Vector::scalar_product(normal, H));
    double Ls = h.hit_object->specular * std::pow(LsI, h.hit_object->specular_exponent);

    return h.color * ((Ld + Ls) * intensity);
}

PointLight::PointLight(const Vector& position, const double& intensity)
        : Light(position), intensity(intensity)
{

}

Color PointLight::apply(Hit h)
{
    double R = (h.hit_point - position).norm();
    Vector normal = (h.hit_point - position) / R;

    double LdI = std::max(0., -Vector::scalar_product(normal, h.normal));
    double Ld = h.hit_object->diffuse * LdI;

    Vector H = (normal + h.ray.direction).unit();
    double LsI = std::max(0., -Vector::scalar_product(normal, H));
    double Ls = h.hit_object->specular * std::pow(LsI, h.hit_object->specular_exponent);

    return h.color * ((Ld + Ls) * intensity / (R * R));
}
