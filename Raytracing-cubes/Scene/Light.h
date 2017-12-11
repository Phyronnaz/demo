#pragma once

#include "Vector.h"
#include "Color.h"
#include "Hit.h"

using namespace rt;

class Light
{
public:
    Vector position;

    explicit Light(const Vector& position) : position(position)
    {

    }

    virtual Color apply(Hit h) = 0;
};

class DirectionalLight : public Light
{
public:
    Vector normal;
    double intensity;

    DirectionalLight(const Vector& normal, const double& intensity);

    Color apply(Hit h) override;
};

class PointLight : public Light
{
public:
    double intensity;

    PointLight(const Vector& position, const double& intensity);

    Color apply(Hit h) override;
};