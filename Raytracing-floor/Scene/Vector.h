#pragma once

/*!
 * The vector class is a struct of 3 double float, they will be used to show
 * positions and directions.
 */
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

    /*!
     * Creates a vector
     * @param a
     * @param b
     * @param c
     */
    Vector(double a, double b, double c) : x(a), y(b), z(c)
    {}

    /*!
     * Vectorial product between left and right vector in this order
     * @param left
     * @param right
     * @return
     */
    static Vector vectorial_product(const Vector& left, const Vector& right);

    /*!
     * Scalar product between left and right vector
     * @param left
     * @param right
     * @return
     */
    static double scalar_product(const Vector& left, const Vector& right);

    double norm() const;
    /*!
     * To limit approximation errors, we create squared_norm
     * @return
     */
    double squared_norm() const;

    /*!
     * Obtains the vector given by the reflection according to the normal
     * of the surface hit
     * @param normal
     * @return
     */
    Vector reflect_around_normal(const Vector& normal);

    /*!
     * Makes the vector a unit vector
     * @return
     */
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