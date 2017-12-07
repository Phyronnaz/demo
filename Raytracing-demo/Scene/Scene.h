#pragma once


#include <vector>
#include "Object.h"
#include "Camera.h"
#include "../Screen/screen.hpp"
#include "Light.h"

class Scene
{
public:
    Scene(const std::vector<Object*>& objects, const std::vector<Light*>& lights,
          Camera* camera, double width, double height);

    void render_scene(rt::screen& screen);

private:
    std::vector<Object*> objects;
    std::vector<Light*> lights;
    Camera* camera;
    double width;
    double height;
};

