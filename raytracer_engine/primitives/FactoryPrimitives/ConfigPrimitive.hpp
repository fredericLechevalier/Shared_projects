/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-theotime.schmeltz
** File description:
** ConfigPrimitive
*/

#pragma once
#include "../IPrimitives.hpp"

namespace RayTracer {
    namespace Primitives {
        class ConfigPrimitive {
            public:
                ConfigPrimitive(const std::string &name) {_name = name;};
                ~ConfigPrimitive() {};
                Math::Point3d point3d;
                double a;
                Math::Vector3d vector3d;
                Math::Vector3d color;
                double x;
                double y;
                double z;
                double height;
                std::string axis;
                std::string _name;
        };
    }
}
