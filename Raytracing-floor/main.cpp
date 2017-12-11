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

    TexturePlane floor(Vector(0, 0, 0), Vector::RIGHT, Vector::FORWARD, "texture_diffuse.png", "texture_normal.png");
//    CheckedPlane floor(Vector(0, 0, 0), Vector::RIGHT, Vector::FORWARD, Color::BLACK, Color::BLACK);
    floor.reflection = 0;

    objects.push_back(&floor);

    std::vector<Light*> lights;
    DirectionalLight dl1(Vector::RIGHT-Vector::UP*0.5,10);
    lights.push_back(&dl1);

    PointLight pl1(Vector(0, -1000, 1000), 100000);
    //lights.push_back(&pl1);

    Camera camera(Vector(0, 0, 500), Vector::FORWARD-Vector::UP, Vector::RIGHT);

    Scene scene(objects, lights, &camera, width, height, "");

    cin.exceptions(ifstream::failbit | ifstream::badbit);
    
    scene.render_scene(current_screen);
    current_screen.update();
    
    dl1.normal = (-Vector::RIGHT - Vector::UP*0.5).unit();
    dl1.intensity = 3;

    scene.render_scene(current_screen);
    current_screen.update();


    double t = 0;
    while (not current_screen.wait_quit_event())
    {
    }

    return 0;
}
