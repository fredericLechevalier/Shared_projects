/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-theotime.schmeltz
** File description:
** FactoryLights
*/

#pragma once

#include "ConfigLights.hpp"

#include <memory>

namespace RayTracer
{
    namespace Lights
    {
        class IFactoryLights {
            public:
                virtual ~IFactoryLights() = default;
                virtual std::unique_ptr<ILights> create() = 0;
                virtual std::unique_ptr<ILights> create(ConfigLights) = 0;
        };
    }
}
