/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-theotime.schmeltz
** File description:
** Camera
*/

#include "Camera.hpp"

RayTracer::Camera::Camera()
{
    origin = Math::Point3d();
    screen = Rectangle3d();
}

RayTracer::Camera::Camera(Math::Point3d origin, Rectangle3d screen)
{
    this->origin = origin;
    this->screen = screen;
}

RayTracer::Camera::Camera(const Camera &cam)
{
    this->origin = cam.origin;
    this->screen = cam.screen;
}

RayTracer::Ray RayTracer::Camera::ray(double u, double v)
{
    Math::Point3d tmp = this->screen.pointAt(u, v);
    return (Ray(this->origin, Math::Vector3d(tmp.x, tmp.y, tmp.z)));
}

void RayTracer::Camera::operator=(const RayTracer::Camera & cam)
{
    this->origin = cam.origin;
    this->screen = cam.screen;
}
