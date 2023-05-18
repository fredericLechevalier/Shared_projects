/*
** EPITECH PROJECT, 2022
** B-OOP-400-MLH-4-1-raytracer-theotime.schmeltz
** File description:
** Ambient.cpp
*/

#include "Ambient.hpp"

RayTracer::Lights::Ambient::Ambient()
{
    
}

RayTracer::Lights::Ambient::Ambient(const Math::Point3d &origin, const Math::Vector3d &direction, const Math::Vector3d &color)
{
    this->origin = origin;
    this->direction = direction;
    this->color = color;
}

RayTracer::Lights::Ambient::~Ambient()
{

}

Math::Vector3d RayTracer::Lights::Ambient::getDirection(void)
{
    return (this->direction);
}

Math::Vector3d RayTracer::Lights::Ambient::getColor(void)
{
    return (this->color);
}

Math::Point3d RayTracer::Lights::Ambient::getOrigin(void)
{
    return (this->origin);
}

std::unique_ptr<RayTracer::Lights::ILights> RayTracer::Lights::FactoryAmbient::create()
{
    return std::make_unique<RayTracer::Lights::Ambient> ();
}

std::unique_ptr<RayTracer::Lights::ILights> RayTracer::Lights::FactoryAmbient::create(ConfigLights cfg)
{
    return std::make_unique<RayTracer::Lights::Ambient> (cfg.origin, cfg.vector, cfg.color);
}

extern "C" {
    std::unique_ptr<RayTracer::Lights::IFactoryLights> getFactory()
    {
        return std::make_unique<RayTracer::Lights::FactoryAmbient>();
    }
}