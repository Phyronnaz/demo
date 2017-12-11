#include "Plane.h"


Plane::Plane(const Vector& position,
             const Vector& vectorx,
             const Vector& vectory)
        : position(position),
          vector_x(vectorx.unit()),
          vector_y(vectory.unit())
{
}

bool Plane::intersect(const Ray& ray, Hit& hit) const
{
    Vector n = Vector::vectorial_product(vector_x, vector_y);

    if(Vector::scalar_product(n, ray.direction) == 0.)
    {
        return false;
    }
    else
    {
        double d = -Vector::scalar_product(n, position);
        double t = -(Vector::scalar_product(n, ray.origin) + d) / Vector::scalar_product(n, ray.direction);

        hit.ray = ray;
        hit.hit_point = ray.origin + t * ray.direction;
        hit.hit_object = this;

        double xcomponent = Vector::scalar_product(hit.hit_point, vector_x) / 4.;
        double ycomponent = Vector::scalar_product(hit.hit_point, vector_y) / 4.;

        hit.color = get_color(xcomponent, ycomponent);
        hit.normal = (n.unit() + get_additional_normal(xcomponent, ycomponent)).unit();

        // 0.5 is to avoid approximations errors
        return t > 0.5;
    }
}
