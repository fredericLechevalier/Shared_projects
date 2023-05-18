/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-theotime.schmeltz
** File description:
** ConfigPrimitive
*/

#pragma once
#include "../ILights.hpp"

namespace RayTracer {
    namespace Lights {
        class ConfigLights {
            public:
                ConfigLights(const std::string &name) {_name = name;};
                ~ConfigLights() {};
                Math::Vector3d vector;
                Math::Vector3d color;
                Math::Point3d origin;
                std::string _name;
        };
    }
}
