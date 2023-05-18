/*
** EPITECH PROJECT, 2022
** B-OOP-400-MLH-4-1-raytracer-theotime.schmeltz
** File description:
** Planes.cpp
*/

#include "Planes.hpp"

RayTracer::Primitives::Planes::Planes()
{
    this->origin = Math::Point3d(0, 0, 0);
    this->color = Math::Vector3d(0, 0, 0);
    this->normal = Math::Vector3d(0, 0, 0);
}

RayTracer::Primitives::Planes::Planes(const Math::Point3d &origin, const Math::Vector3d &normal, const Math::Vector3d &color)
{
    this->color = color;
    this->origin = origin;
    this->normal = normal;
}

RayTracer::Primitives::Planes::~Planes()
{

}

void RayTracer::Primitives::Planes::translate(const Math::Vector3d &vector)
{
    this->origin.x += vector.x;
    this->origin.y += vector.y;
    this->origin.z += vector.z;
}

bool RayTracer::Primitives::Planes::hits(Ray &ray)
{
    float denom = normal.dot(ray.vector);
    if (std::abs(denom) > 0.0001f) {
        float t = (this->origin - ray.point).dot(normal) / denom;
        return (t >= 0);
    }
    return false;
}

void RayTracer::Primitives::Planes::rotate(double rotate)
{

}

void RayTracer::Primitives::Planes::scale(double scale)
{

}

Math::Vector3d RayTracer::Primitives::Planes::getColor(void)
{
    return (this->color);
}

Math::Point3d RayTracer::Primitives::Planes::getOrigin(void)
{
    return (this->origin);
}

double RayTracer::Primitives::Planes::getRoot(Ray &ray)
{
    float denom = normal.dot(ray.vector);
    float t = (this->origin - ray.point).dot(normal) / denom;
    return (t);
}

Math::Vector3d RayTracer::Primitives::Planes::getNormal(const Math::Point3d &point)
{
    return (this->normal);
}

std::unique_ptr<RayTracer::Primitives::IPrimitives> RayTracer::Primitives::FactoryPlane::create()
{
    return std::make_unique<RayTracer::Primitives::Planes>();
}

std::unique_ptr<RayTracer::Primitives::IPrimitives> RayTracer::Primitives::FactoryPlane::create(RayTracer::Primitives::ConfigPrimitive params)
{
    return std::make_unique<RayTracer::Primitives::Planes>(params.point3d, params.vector3d, params.color);
}

extern "C" {
    std::unique_ptr<RayTracer::Primitives::IFactoryPrimitives> getFactory()
    {
        return std::make_unique<RayTracer::Primitives::FactoryPlane>();
    }
}