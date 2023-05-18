/*
** EPITECH PROJECT, 2022
** Test
** File description:
** Rectangle3d.hpp
*/

#pragma once
#include "../primitives/Sphere/Sphere.hpp"

namespace RayTracer
{
    class Rectangle3d
    {
    public:
        Rectangle3d()
        {
            origin = Math::Point3d(0, 0, 0);
            bottom_side = Math::Vector3d(0, 1, 0);
            left_side = Math::Vector3d(1, 0, 0);
        }

        Rectangle3d(Math::Point3d point, Math::Vector3d botVector, Math::Vector3d leftVector)
        {
            origin = point;
            bottom_side = botVector;
            left_side = leftVector;
        }
        
        Rectangle3d(const Rectangle3d &og)
        {
            origin = og.origin;
            bottom_side = og.bottom_side;
            left_side = og.left_side;
        }

        Math::Point3d pointAt(double u, double v)
        {
            Math::Point3d out(this->origin.x + (u * this->bottom_side.x) + (v * this->left_side.x),
            this->origin.y + (u * this->bottom_side.y) + (v * this->left_side.y),
            this->origin.z + (u * this->bottom_side.z) + (v * this->left_side.z));
            return (out);
        }

        Math::Point3d origin;
        Math::Vector3d bottom_side;
        Math::Vector3d left_side;
    };
}
