cmake_minimum_required(VERSION 3.7)
project(Raycasting)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp
        Screen/image.cpp
        Screen/image.hpp
        Screen/rect.hpp
        Screen/screen.cpp
        Screen/screen.hpp
        Screen/color.hpp
        Screen/color.cpp
        Screen/vector.hpp
        Screen/vector.cpp

        Scene/Color.cpp
        Scene/Color.h
        Scene/Vector.cpp
        Scene/Vector.h
        Scene/Camera.h
        Scene/Object.h
        Scene/Sphere.cpp
        Scene/Sphere.h
        Scene/Hit.h
        Scene/Ray.h
        Scene/Scene.h
        Scene/Scene.cpp
        Scene/Light.h
        Scene/Light.cpp
        Scene/Plane.h
        Scene/Plane.cpp)
add_executable(Raycasting ${SOURCE_FILES})

find_package(SDL REQUIRED)
include_directories(${SDL_INCLUDE_DIR})
target_link_libraries (Raycasting ${SDL_LIBRARY})
