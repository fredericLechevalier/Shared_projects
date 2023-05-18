/*
** EPITECH PROJECT, 2022
** Test
** File description:
** Camera.hpp
*/

#pragma once
#include "../maths/Rectangle3d.hpp"

namespace RayTracer
{
    class Camera
    {
    public:
        Camera();
        Camera(Math::Point3d origin, Rectangle3d screen);
        Camera(const Camera &cam);
        void operator=(const Camera &cam);
        ~Camera() {};
        Ray ray(double u, double v);

        Math::Point3d origin;
        Rectangle3d screen;
    };
}
