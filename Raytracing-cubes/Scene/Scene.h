#pragma once


#include <vector>
#include "Object.h"
#include "Camera.h"
#include "../Screen/screen.hpp"
#include "Light.h"

class Scene
{
public:
    Scene(const std::vector<Object*>& objects,
          const std::vector<Light*>& lights,
          Camera* camera,
          double width,
          double height,
          char const* filename
    );

    void render_scene(rt::screen& screen);

private:
    std::vector<Object*> objects;
    std::vector<Light*> lights;
    Camera* camera;

    double width;
    double height;

    unsigned char* diffuse_data;
    int diffuse_x, diffuse_y, diffuse_n;

    void render_thread(int starti,
                       int endi,
                       int startj,
                       int endj,
                       int screen_width,
                       int screen_height,
                       std::vector<rt::color>& out_colors);
};

