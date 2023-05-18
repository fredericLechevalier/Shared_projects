#include "Torus.hpp"

RayTracer::Primitives::Torus::Torus()
{
    this->radius = 0;
    this->center = Math::Point3d();
    this->color = Math::Vector3d(0, 0, 0);
}

RayTracer::Primitives::Torus::Torus(const Math::Point3d &point, double radius, const Math::Vector3d &color)
{
    this->radius = radius;
    this->center = point;
    this->color = color;
}

void RayTracer::Primitives::Torus::rotate(double rotate)
{

}

void RayTracer::Primitives::Torus::scale(double scale)
{
    this->radius *= scale;
}

RayTracer::Primitives::Torus::~Torus()
{

}

bool RayTracer::Primitives::Torus::hits(Ray &ray)
{
    double test;
    Math::Vector3d origin(ray.point.x - this->center.x, ray.point.y - this->center.y, ray.point.z - this->center.z);
    Math::Vector3d d(ray.vector.x - ray.point.x, ray.vector.y - ray.point.y, ray.vector.z - ray.point.z);
    double a = d.dot(d);
    double b = 2 * origin.dot(d);
    double c = origin.dot(origin) - pow(radius, 2);
    test = pow(b, 2) - 4 * a * c;
    return (test >= 0);
}

void RayTracer::Primitives::Torus::translate(const Math::Vector3d &vector)
{
    this->center.x += vector.x;
    this->center.y += vector.y;
    this->center.z += vector.z;
}

double RayTracer::Primitives::Torus::getRoot(Ray &ray)
{
    double test;
    Math::Vector3d origin(ray.point.x - this->center.x, ray.point.y - this->center.y, ray.point.z - this->center.z);
    Math::Vector3d d(ray.vector.x - ray.point.x, ray.vector.y - ray.point.y, ray.vector.z - ray.point.z);
    double a = d.dot(d);
    double b = 2 * origin.dot(d);
    double c = origin.dot(origin) - pow(radius, 2);
    test = pow(b, 2) - 4 * a * c;
    if (test == 0)
        return (-b / (2 * a));
    double root1 = (-b - sqrt(test)) / (2 * a);
    double root2 = (-b + sqrt(test)) / (2 * a);
    if (root1 < root2)
        return (root1);
    return (root2);
}

Math::Vector3d RayTracer::Primitives::Torus::getNormal(const Math::Point3d &point)
{
    Math::Vector3d tmp(point.x - center.x, point.y - center.y, point.z - center.z);
    double tmpDot = tmp.dot(tmp);
    if (tmpDot != 0.0)
        tmp /= sqrt(tmpDot);
    return (tmp);
}

Math::Vector3d RayTracer::Primitives::Torus::getColor(void)
{
    return (this->color);
}

Math::Point3d RayTracer::Primitives::Torus::getOrigin(void)
{
    return (this->center);
}


std::unique_ptr<RayTracer::Primitives::IPrimitives> RayTracer::Primitives::FactoryTorus::create()
{
    return std::make_unique<RayTracer::Primitives::Torus>();
}

std::unique_ptr<RayTracer::Primitives::IPrimitives> RayTracer::Primitives::FactoryTorus::create(RayTracer::Primitives::ConfigPrimitive params)
{
    return std::make_unique<RayTracer::Primitives::Torus>(params.point3d, params.a, params.color);
}

extern "C" {
    std::unique_ptr<RayTracer::Primitives::IFactoryPrimitives> getFactory()
    {
        return std::make_unique<RayTracer::Primitives::FactoryTorus>();
    }
}