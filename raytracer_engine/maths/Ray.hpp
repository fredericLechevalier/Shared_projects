/*
** EPITECH PROJECT, 2022
** Test
** File description:
** Ray.hpp
*/

#pragma once
#include "Point3d.hpp"

namespace RayTracer
{
    class Ray
    {
    public:
        Ray()
        {
            this->point = Math::Point3d();
            this->vector = Math::Vector3d();
        }
        
        Ray(const Math::Point3d &point, const Math::Vector3d &vector)
        {
            this->point = point;
            this->vector = vector;
        }

        Ray(const Ray &ray)
        {
            this->point = ray.point;
            this->vector = ray.vector;
        }

        void operator=(const Ray &ray)
        {
            this->point = ray.point;
            this->vector = ray.vector;
        }

        Ray(Ray &ray)
        {
            this->point = ray.point;
            this->vector = ray.vector;
        }

        void operator=(Ray &ray)
        {
            this->point = ray.point;
            this->vector = ray.vector;
        }

        Math::Point3d point;
        Math::Vector3d vector;
    };
}
