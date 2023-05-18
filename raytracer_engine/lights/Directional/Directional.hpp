/*
** EPITECH PROJECT, 2022
** B-OOP-400-MLH-4-1-raytracer-theotime.schmeltz
** File description:
** Directional.hpp
*/

#pragma once
#include "../ILights.hpp"
#include "../FactoryLights/IFactoryLights.hpp"

namespace RayTracer
{
    namespace Lights {
        class Directional : public ILights
        {
            public:
                Directional();
                Directional(const Math::Point3d &origin, const Math::Vector3d &direction, const Math::Vector3d &color);
                ~Directional();
                Math::Vector3d getDirection(void);
                Math::Vector3d getColor(void);
                Math::Point3d getOrigin(void);
            private:
                Math::Point3d origin;
                Math::Vector3d color;
                Math::Vector3d direction;
        };
        class FactoryDirectional : public RayTracer::Lights::IFactoryLights
        {
            public :
                std::unique_ptr<ILights> create();
                std::unique_ptr<ILights> create(ConfigLights);
        };
    }
}
