#pragma once

#include <vector>
#include "Object.h"
#include "Camera.h"
#include "../Screen/screen.hpp"
#include "Light.h"

/*!
 * The scene is created from a camera, list of objects and a list of lights,
 * and render them
 */
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

    /*!
     * Render the scene on the screen
     * @param screen the screen to render on
     */
    void render_scene(rt::screen& screen);

private:
    std::vector<Object*> objects;
    std::vector<Light*> lights;
    Camera* camera;

    double width;
    double height;

    unsigned char* diffuse_data;
    int diffuse_x, diffuse_y, diffuse_n;

    /*!
     * Render thread
     * @param starti left
     * @param endi right
     * @param startj bottom
     * @param endj top
     * @param screen_width width of screen
     * @param screen_height height of screen
     * @param out_colors The array to put colors in
     */
    void render_thread(int starti,
                       int endi,
                       int startj,
                       int endj,
                       int screen_width,
                       int screen_height,
                       std::vector<rt::color>& out_colors);
};

