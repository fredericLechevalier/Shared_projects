/*
** EPITECH PROJECT, 2022
** B-OOP-400-MLH-4-1-raytracer-theotime.schmeltz
** File description:
** ILights.hpp
*/

#pragma once
#include "../maths/Vector3d.hpp"
#include "../maths/Point3d.hpp"
#include "../maths/Ray.hpp"

namespace RayTracer
{
    namespace Lights
    {
        class ILights
        {
            public:
                virtual ~ILights() {};
                virtual Math::Vector3d getDirection(void) = 0;
                virtual Math::Vector3d getColor(void) = 0;
                virtual Math::Point3d getOrigin(void) = 0;
        };
    }
}
