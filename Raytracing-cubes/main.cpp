#include <iostream>
#include <unistd.h>
#include <fstream>
#include <cassert>
#include <vector>
#include <ctime>
#include <sys/time.h>
#include <cmath>

#include "Screen/image.hpp"
#include "Screen/screen.hpp"
#include "Scene/Color.h"
#include "Scene/Camera.h"
#include "Scene/Vector.h"
#include "Scene/Sphere.h"
#include "Scene/Scene.h"
#include "Scene/Plane.h"
#include "Scene/TexturePlane.h"
#include "Scene/CheckedPlane.h"

using namespace std;
using namespace rt;

int main(int argc, char* argv[])
{
    int width = 1000;
    int height = 1000;
    screen current_screen(width / 2, height / 2);

    std::vector<Object*> objects;
//
//    for (int x = -5000; x <= 5000; x += 1000)
//    {
//        Sphere* center = new Sphere(Vector(x, 0, 500), 490, Color::RED);
//        center->reflection = (x + 5000) / 10000.;
//        objects.push_back((Object*) center);
//    }

    Sphere center(Vector(0, 0, 100), 50, Color::WHITE);
    objects.push_back(&center);

    double size = 1000;
    double factor = 5;
    Color color_1 = Color(250, 250, 250) * 8;
    Color color_2 = Color(255, 0, 0) * 8;
    Color color_3 = Color(255, 128, 10) * 8;
    Color color_4 = Color(0, 255, 0) * 8;
    Color color_5 = Color(255, 128, 0);
    Color color_6 = Color(0, 0, 255) * 8;


    CheckedPlane wall_1(Vector(-size, -size, size), Vector::RIGHT, Vector::FORWARD, color_1, color_1);
    wall_1.reflection = 0.9;
    CheckedPlane wall_2(Vector(-size, -size, 0), Vector::RIGHT, Vector::UP, color_2, color_2);
    wall_2.reflection = 0.9;
    CheckedPlane wall_3(Vector(-size, -size, 0), Vector::FORWARD, Vector::UP, color_3, color_3);
    wall_3.reflection = 0.9;
    CheckedPlane wall_4(Vector(size, -size, 0), Vector::FORWARD, Vector::UP, color_4, color_4);
    wall_4.reflection = 0.9;
    CheckedPlane wall_5(Vector(0, 0, -size), Vector::RIGHT, Vector::FORWARD, color_5, color_5);
    wall_5.reflection = 0;
    CheckedPlane wall_6(Vector(size, size, 0), Vector::RIGHT, Vector::UP, color_6, color_6);
    wall_6.reflection = 0.9;
    objects.push_back(&wall_1);
    objects.push_back(&wall_2);
    objects.push_back(&wall_3);
    objects.push_back(&wall_4);
    objects.push_back(&wall_5);
    objects.push_back(&wall_6);

    std::vector<Light*> lights;
    DirectionalLight dl1(Vector::FORWARD - Vector::UP, 0.01);
    lights.push_back(&dl1);

    PointLight pl1(Vector(200, -50, 200), 15000);
    lights.push_back(&pl1);

    Camera camera(Vector(0, -500, 200), Vector::FORWARD - Vector::UP * 0.1, Vector::RIGHT);

    Scene scene(objects, lights, &camera, width, height, "sky.jpg");

    timeval start;
    gettimeofday(&start, 0);

    scene.render_scene(current_screen);
    current_screen.update();

    timeval end;
    gettimeofday(&end, 0);

    double duration = end.tv_sec + end.tv_usec / 1000000. - start.tv_sec - start.tv_usec / 1000000.;

    std::cout << "Time: " << duration << std::endl;

    cin.exceptions(ifstream::failbit | ifstream::badbit);

    while (not current_screen.wait_quit_event())
    {

    }

    return 0;
}
