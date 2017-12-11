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

    for (int x = -5000; x <= 5000; x += 1000)
    {
        Sphere* center = new Sphere(Vector(x, 0, 500), 490, Color::RED);
        center->reflection = (x + 5000) / 10000.;
        objects.push_back((Object*) center);
    }


    TexturePlane floor(Vector(0, 0, 0), Vector::RIGHT, Vector::FORWARD, "texture_diffuse.png", "texture_normal.png");
//    CheckedPlane floor(Vector(0, 0, 0), Vector::RIGHT, Vector::FORWARD, Color::BLACK, Color::BLACK);
    floor.reflection = 0.3;

    objects.push_back(&floor);

    std::vector<Light*> lights;
    DirectionalLight dl1(-Vector::UP * 0.1 - Vector::FORWARD, 0.1);
    lights.push_back(&dl1);

    PointLight pl1(Vector(0, -1000, 1000), 100000);
    lights.push_back(&pl1);

    Camera camera(Vector(0, -5000, 100), Vector::FORWARD, Vector::RIGHT);

    Scene scene(objects, lights, &camera, width, height, "sky_2.jpg");

    timeval start;
    gettimeofday(&start, 0);

//    scene.render_scene(current_screen);
//    current_screen.update();

    timeval end;
    gettimeofday(&end, 0);

    double duration = end.tv_sec + end.tv_usec / 1000000. - start.tv_sec - start.tv_usec / 1000000.;

    std::cout << "Time: " << duration << std::endl;

    cin.exceptions(ifstream::failbit | ifstream::badbit);

    double t = 0;
    while (true)
    {
        camera.position = Vector(std::cos(t), std::sin(t), 0.1) * 25000;
        camera.direction = -camera.position.unit();
        camera.orientation = Vector::vectorial_product(camera.direction, Vector::UP).unit();

        timeval start;
        gettimeofday(&start, 0);

        scene.render_scene(current_screen);
        current_screen.update();

        timeval end;
        gettimeofday(&end, 0);


        double duration = end.tv_sec + end.tv_usec / 1000000. - start.tv_sec - start.tv_usec / 1000000.;

        std::cout << "Time: " << duration << std::endl;


        t += duration / 10;
    }

    return 0;
}