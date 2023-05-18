/*
** EPITECH PROJECT, 2022
** B-OOP-400-MLH-4-1-raytracer-theotime.schmeltz
** File description:
** Directional.cpp
*/

#include "Directional.hpp"

RayTracer::Lights::Directional::Directional()
{
    
}

RayTracer::Lights::Directional::Directional(const Math::Point3d &origin, const Math::Vector3d &direction, const Math::Vector3d &color)
{
    this->origin = origin;
    this->direction = direction;
    this->color = color;
}

RayTracer::Lights::Directional::~Directional()
{

}

Math::Vector3d RayTracer::Lights::Directional::getDirection(void)
{
    return (this->direction);
}

Math::Vector3d RayTracer::Lights::Directional::getColor(void)
{
    return (this->color);
}

Math::Point3d RayTracer::Lights::Directional::getOrigin(void)
{
    return (this->origin);
}

std::unique_ptr<RayTracer::Lights::ILights> RayTracer::Lights::FactoryDirectional::create()
{
    return std::make_unique<RayTracer::Lights::Directional> ();
}

std::unique_ptr<RayTracer::Lights::ILights> RayTracer::Lights::FactoryDirectional::create(ConfigLights cfg)
{
    return std::make_unique<RayTracer::Lights::Directional> (cfg.origin, cfg.vector, cfg.color);
}

extern "C" {
    std::unique_ptr<RayTracer::Lights::IFactoryLights> getFactory()
    {
        return std::make_unique<RayTracer::Lights::FactoryDirectional>();
    }
}