#pragma once

struct Vector
{

    double x;
    double y;
    double z;

    static const Vector RIGHT;
    static const Vector FORWARD;
    static const Vector UP;
    static const Vector ZERO_VECTOR;

    Vector() : x(0.0), y(0.0), z(0.0)
    {}

    Vector(double a, double b, double c) : x(a), y(b), z(c)
    {}

    static Vector vectorial_product(const Vector& left, const Vector& right);

    static double scalar_product(const Vector& left, const Vector& right);

    double norm() const;
    double squared_norm() const;

    Vector reflect_around_normal(const Vector& normal);

    Vector unit() const;


    bool operator==(const Vector& other) const;

    Vector& operator+=(const Vector& other);
    Vector& operator-=(const Vector& other);
    Vector& operator*=(const Vector& other);
    Vector& operator/=(const Vector& other);

    Vector& operator*=(const double& other);
    Vector& operator/=(const double& other);

    Vector operator-() const;
};

Vector const operator+(const Vector& left, const Vector& right);
Vector const operator-(const Vector& left, const Vector& right);
Vector const operator*(const Vector& left, const Vector& right);
Vector const operator/(const Vector& left, const Vector& right);

Vector const operator*(const Vector& left, const double& right);
Vector const operator/(const Vector& left, const double& right);
Vector const operator*(const double& left, const Vector& right);