#include <cmath>

#include "Vector.h"

const Vector Vector::RIGHT(1, 0, 0);
const Vector Vector::FORWARD(0, 1, 0);
const Vector Vector::UP(0, 0, 1);
const Vector Vector::ZERO_VECTOR(0, 0, 0);


Vector Vector::vectorial_product(const Vector& left, const Vector& right)
{
    return Vector((left.y * right.z) - (left.z * right.y),
                  (left.z * right.x) - (left.x * right.z),
                  (left.x * right.y) - (left.y * right.x));

}

double Vector::scalar_product(const Vector& left, const Vector& right)
{
    return (left.x * right.x + left.y * right.y + left.z * right.z);
}

double Vector::norm() const
{
    double n = std::sqrt((x * x) + (y * y) + (z * z));
    return n;
}

Vector Vector::unit() const
{
    double n = norm();
    Vector v((x / n), (y / n), (z / n));
    return v;
}

double Vector::squared_norm() const
{
    return (x * x) + (y * y) + (z * z);
}

Vector Vector::reflect_around_normal(const Vector& normal)
{
    return 2 * Vector::scalar_product(*this, normal) * normal - *this;
}


bool Vector::operator==(const Vector& other) const
{
    return ((other.x == x) && (other.y == y) && (other.z == z));
}

Vector& Vector::operator+=(const Vector& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Vector& Vector::operator-=(const Vector& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

Vector& Vector::operator*=(const Vector& other)
{
    x *= other.x;
    y *= other.y;
    z *= other.z;
    return *this;
}

Vector& Vector::operator/=(const Vector& other)
{
    x /= other.x;
    y /= other.y;
    z /= other.z;
    return *this;
}

Vector& Vector::operator*=(const double& other)
{
    x *= other;
    y *= other;
    z *= other;
    return *this;
}

Vector& Vector::operator/=(const double& other)
{
    x /= other;
    y /= other;
    z /= other;
    return *this;
}

Vector Vector::operator-() const
{
    return Vector(-x, -y, -z);
}

Vector const operator+(const Vector& left, const Vector& right)
{
    return Vector(left) += right;
}

Vector const operator-(const Vector& left, const Vector& right)
{
    return Vector(left) -= right;
}

Vector const operator*(const Vector& left, const Vector& right)
{
    return Vector(left) *= right;
}

Vector const operator/(const Vector& left, const Vector& right)
{
    return Vector(left) /= right;
}

Vector const operator*(const Vector& left, const double& right)
{
    return Vector(left) *= right;
}

Vector const operator/(const Vector& left, const double& right)
{
    return Vector(left) /= right;
}

Vector const operator*(const double& left, const Vector& right)
{
    return Vector(right) *= left;
}

