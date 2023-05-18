/*
** EPITECH PROJECT, 2022
** Test
** File description:
** Sphere.hpp
*/

#pragma once
#include "../FactoryPrimitives/IFactoryPrimitives.hpp"

namespace RayTracer
{
    namespace Primitives {
        class Sphere : public IPrimitives
        {
            public:
                Sphere();
                Sphere(const Math::Point3d &point, double radius, const Math::Vector3d &color);
                ~Sphere();
                bool hits(Ray &ray);
                Math::Vector3d getColor(void);
                Math::Point3d getOrigin(void);
                double getRoot(Ray &ray);
                Math::Vector3d getNormal(const Math::Point3d &point);
                void translate(const Math::Vector3d &vector);
                void rotate(double rotate);
                void scale(double scale);
            private :
                Math::Point3d center;
                double radius;
                Math::Vector3d color;
        };
        class FactorySphere : public IFactoryPrimitives {
            public :
                std::unique_ptr<IPrimitives> create();
                std::unique_ptr<IPrimitives> create(ConfigPrimitive);
        };
    }
}
