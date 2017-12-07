#include <iostream>
#include <unistd.h>
#include <fstream>
#include <cassert>
#include <vector>

#include "Screen/image.hpp"
#include "Screen/screen.hpp"
#include "Scene/Color.h"
#include "Scene/Camera.h"
#include "Scene/Vector.h"
#include "Scene/Sphere.h"
#include "Scene/Scene.h"
#include "Scene/Plane.h"

using namespace std;
using namespace rt;

static void draw_rectangle(screen& s, int x, int y, int width, Color c)
{
    s.fill_rect(x, y, x + width - 1, y + width - 1, c);
}

static void draw_centered_cross(screen& s, int x, int y, int width, Color c)
{
    assert(width > 0);
    int my_x = x - width / 2;
    int my_y = y - width / 2;
    //(s, my_x, my_y, width, c);
    draw_rectangle(s, my_x, my_y, width, c);
    draw_rectangle(s, my_x + width, my_y, width, c);
    draw_rectangle(s, my_x - width, my_y, width, c);
    draw_rectangle(s, my_x, my_y + width, width, c);
    draw_rectangle(s, my_x, my_y - width, width, c);
    s.set_pixel(x, y, Color::RED);
}

int main(int argc, char* argv[])
{

    clog << "Argument number: " << argc << endl;
    for (int i = 0; i < argc; i++)
        clog << "Argument " << i << ": " << argv[i] << endl;
    clog << string(50, '_') << endl;

    int width = 1920;
    int height = 1080;
    screen current_screen(width, height);

    Sphere s1(Vector(500, 500, 100), 25.0, Color::GREEN);
    Sphere s2(Vector(500, 500, 600), 100.0, Color::RED);

    Plane p1(Vector(0, 600, 0), Vector::RIGHT, Vector::UP, Color::BLUE);

    std::vector<Object*> objects;
    objects.push_back(&s1);
    objects.push_back(&s2);
    objects.push_back(&p1);

    std::vector<Light*> lights;
    DirectionalLight l1(-Vector::UP, 0.75);
    PointLight pl1(Vector::RIGHT * 100, 1000000);
//    lights.push_back(&l1);
    lights.push_back(&pl1);

    Camera camera(Vector(0, 0, 0), Vector(0.0, 0.0, 1.0));

    Scene scene(objects, lights, &camera, width, height);

    scene.render_scene(current_screen);
    current_screen.update();

    cin.exceptions(ifstream::failbit | ifstream::badbit);

    // wait for the screen to be closed
    clog << "Waiting for QUIT event...";
    while (not current_screen.wait_quit_event())
    {}

    return 0;
}
