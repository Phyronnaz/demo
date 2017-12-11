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
    screen current_screen(width, height);

    std::vector<Object*> objects;

    Sphere sphere(Vector(0,750,100),100,Color::RED);
    sphere.reflection = 0.4;

    Sphere sphere2(Vector(175,750,100),50,Color::GREEN);
    sphere2.reflection = 0.2;

    //   TexturePlane floor(Vector(0, 0, 0), Vector::RIGHT, Vector::FORWARD, "texture_diffuse.png", "texture_normal.png");
    CheckedPlane floor(Vector(0, 0, 0), Vector::RIGHT, Vector::FORWARD, Color::WHITE, Color::BLACK);
    floor.reflection = 0.4;

    objects.push_back(&floor);
    objects.push_back(&sphere);
    objects.push_back(&sphere2);

    std::vector<Light*> lights;
    DirectionalLight dl1(-Vector::UP , 1);
    lights.push_back(&dl1);

    PointLight pl1(Vector(0, -1000, 250), 1000000);
    lights.push_back(&pl1);

    Camera camera(Vector(0, -500, 250), Vector::FORWARD-Vector::UP/8, Vector::RIGHT);

    Scene scene(objects, lights, &camera, width, height, "");

    timeval start;
    gettimeofday(&start, 0);

    scene.render_scene(current_screen);
    current_screen.update();

    timeval end;
    gettimeofday(&end, 0);

    double duration = end.tv_sec + end.tv_usec / 1000000. - start.tv_sec - start.tv_usec / 1000000.;

    std::cout << "Time: " << duration << std::endl;

    cin.exceptions(ifstream::failbit | ifstream::badbit);

    double t = 0;
    while (not current_screen.wait_quit_event())
    {

    }

    return 0;
}