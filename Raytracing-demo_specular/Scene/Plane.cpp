
#include <cmath>
#include "Plane.h"


Plane::Plane(const Vector& position, const Vector& vectorx, const Vector& vectory, const Color& color,
             const double diffuse, const double specular, const double specular_exponent)
        : position(position), vectorx(vectorx.unit()), vectory(vectory.unit()),
          Object(color, diffuse, specular, specular_exponent)
{}

bool Plane::intersect(const Ray& ray, Hit& hit) const
{
    Vector n = Vector::vectorial_product(vectorx, vectory);

    if(Vector::scalar_product(n, ray.direction) == 0.)
    {
        return false;
    }
    else
    {
        double d = -Vector::scalar_product(n, position);
        double t = -(Vector::scalar_product(n, ray.origin) + d) / Vector::scalar_product(n, ray.direction);

        hit.ray = ray;
        hit.color = color;
        hit.hit_point = ray.origin + t * ray.direction;
        hit.normal = n.unit();
        hit.hit_object = this;
        return t > 0.5;
    }
}
