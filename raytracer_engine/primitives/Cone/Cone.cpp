/*
** EPITECH PROJECT, 2022
** B-OOP-400-MLH-4-1-raytracer-theotime.schmeltz
** File description:
** Cone.cpp
*/

#include "Cone.hpp"

RayTracer::Primitives::Cone::Cone()
{

}

RayTracer::Primitives::Cone::Cone(const Math::Point3d &point, double radius, double height, const Math::Vector3d &color, const Math::Vector3d &direction)
{
    this->origin = point;
    this->radius = radius;
    this->height = height;
    this->color = color;
    this->direction = direction;
}

RayTracer::Primitives::Cone::~Cone()
{

}

/*

    i.n_dir = 1;
    k = tan(cone->angle);
    ori_cen = v_sub(ray->origin, cone->pos);
    i.q.x = v_dot(ray->dir, ray->dir) - (1.0 + k * k) * powf(v_dot(ray->dir, cone->dir), 2.0);
    i.q.y = 2 * (v_dot(ray->dir, ori_cen) - (1.0 + k * k) * v_dot(ray->dir, cone->dir)
                * v_dot(ori_cen, cone->dir));
    i.q.z = v_dot(ori_cen, ori_cen) - (1.0 + k * k) * powf(v_dot(ori_cen,
                cone->dir), 2.0);

*/

void RayTracer::Primitives::Cone::rotate(double rotate)
{

}

void RayTracer::Primitives::Cone::scale(double scale)
{

}

bool RayTracer::Primitives::Cone::hits(Ray &ray)
{
    Math::Vector3d origin(ray.point.x - this->origin.x, ray.point.y - this->origin.y, ray.point.z - this->origin.z);
    double angle = std::tan(this->radius);
    double a = ray.vector.dot(ray.vector) - (1.0 + angle * angle) * std::pow(ray.vector.dot(this->direction), 2.0);
    double b = 2.0 * (ray.vector.dot(origin)) - (1.0 + angle * angle) * ray.vector.dot(this->direction) * origin.dot(this->direction);
    double c = origin.dot(origin) - (1.0 + angle * angle) * std::pow(origin.dot(this->direction), 2.0);

    double t = (b * b) - 4 * a * c;
    return (t >= 0);
}

Math::Vector3d RayTracer::Primitives::Cone::getColor(void)
{
    return (this->color);
}

Math::Point3d RayTracer::Primitives::Cone::getOrigin(void)
{
    return (this->origin);
}

double RayTracer::Primitives::Cone::getRoot(Ray &ray)
{
    return 0.0;
}

Math::Vector3d RayTracer::Primitives::Cone::getNormal(const Math::Point3d &point)
{
    Math::Vector3d tmp(0.0, 0.0, 0.0);
    return (tmp);
}

void RayTracer::Primitives::Cone::translate(const Math::Vector3d &vector)
{
    this->origin.x += vector.x;
    this->origin.y += vector.y;
    this->origin.z += vector.z;
}

std::unique_ptr<RayTracer::Primitives::IPrimitives> RayTracer::Primitives::FactoryCone::create()
{
    return std::make_unique<RayTracer::Primitives::Cone>();
}

std::unique_ptr<RayTracer::Primitives::IPrimitives> RayTracer::Primitives::FactoryCone::create(RayTracer::Primitives::ConfigPrimitive params)
{
    return std::make_unique<RayTracer::Primitives::Cone>(params.point3d, params.a, params.x, params.color, params.vector3d);
}

extern "C" {
    std::unique_ptr<RayTracer::Primitives::IFactoryPrimitives> getFactory()
    {
        return std::make_unique<RayTracer::Primitives::FactoryCone>();
    }
}
