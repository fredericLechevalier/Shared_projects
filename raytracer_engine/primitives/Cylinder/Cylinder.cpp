/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-theotime.schmeltz
** File description:
** Cylinder
*/

#include "Cylinder.hpp"

RayTracer::Primitives::Cylinder::Cylinder()
{

}

RayTracer::Primitives::Cylinder::Cylinder(const Math::Point3d &point, double radius, double h, Math::Vector3d &color)
{
    this->color = color;
    this->center = point;
    this->height = h;
    this->radius = radius;
}

RayTracer::Primitives::Cylinder::~Cylinder()
{

}

void RayTracer::Primitives::Cylinder::rotate(double rotate)
{

}

void RayTracer::Primitives::Cylinder::scale(double scale)
{
    this->height *= scale;
    this->radius *= scale;
}

bool RayTracer::Primitives::Cylinder::hits(Ray &ray)
{
    double test;
    if (this->height < 0 && ray.vector.y > height + this->center.y)
        return false;
    if (this->height > 0 && ray.vector.y < this->height + this->center.y)
        return false;
    Math::Vector3d origin(ray.point.x - this->center.x, ray.point.y - this->center.y, ray.point.z - this->center.z);
    Math::Vector3d d(ray.vector.x - ray.point.x, 0, ray.vector.z - ray.point.z);
    double a = d.dot(d);
    double b = 2 * origin.dot(d);
    double c = origin.dot(origin) - pow(radius, 2);

    double discriminant = std::pow(b, 2.0) - (4.0 * (a * c));
    return discriminant > 0;
}

Math::Vector3d RayTracer::Primitives::Cylinder::getColor(void)
{
    return this->color;
}

Math::Point3d RayTracer::Primitives::Cylinder::getOrigin(void)
{
    return this->center;
}

double RayTracer::Primitives::Cylinder::getRoot(RayTracer::Ray &ray)
{
    Math::Vector3d origin(ray.point.x - this->center.x, ray.point.y - this->center.y, ray.point.z - this->center.z);
    Math::Vector3d d(ray.vector.x - ray.point.x, 0, ray.vector.z - ray.point.z);
    double a = d.dot(d);
    double b = 2 * origin.dot(d);
    double c = origin.dot(origin) - pow(radius, 2);

    double discriminant = std::pow(b, 2.0) - (4.0 * (a * c));
    double root = 0.0;
    if (discriminant > 0)
    {
            root = (-1 * b - sqrt(discriminant)) / 2 * a;
            if (root <= 0)
                    root = (-1 * b + sqrt(discriminant)) / 2 * a;
            return (root);
    }
    return (-1);
}

Math::Vector3d RayTracer::Primitives::Cylinder::getNormal(const Math::Point3d &point)
{
    Math::Vector3d tmp(point.x - center.x, point.y - center.y, point.z - center.z);
    double tmpDot = tmp.dot(tmp);
    if (tmpDot != 0.0)
        tmp /= sqrt(tmpDot);
    return (tmp);
}

void RayTracer::Primitives::Cylinder::translate(const Math::Vector3d &vector)
{
    this->center.x += vector.x;
    this->center.y += vector.y;
    this->center.z += vector.z;
}

std::unique_ptr<RayTracer::Primitives::IPrimitives> RayTracer::Primitives::FactoryCylinder::create()
{
    return std::make_unique<RayTracer::Primitives::Cylinder>();
}

std::unique_ptr<RayTracer::Primitives::IPrimitives> RayTracer::Primitives::FactoryCylinder::create(RayTracer::Primitives::ConfigPrimitive params)
{
    return std::make_unique<RayTracer::Primitives::Cylinder>(params.point3d, params.a, params.height, params.color);
}

extern "C" {
    std::unique_ptr<RayTracer::Primitives::IFactoryPrimitives> getFactory()
    {
        return std::make_unique<RayTracer::Primitives::FactoryCylinder>();
    }
}