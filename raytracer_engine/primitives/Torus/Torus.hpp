/*
** EPITECH PROJECT, 2022
** Test
** File description:
** Torus.hpp
*/

#pragma once
#include "../FactoryPrimitives/IFactoryPrimitives.hpp"

namespace RayTracer
{
    namespace Primitives {
        class Torus : public IPrimitives
        {
            public:
                Torus();
                Torus(const Math::Point3d &point, double radius, const Math::Vector3d &color);
                ~Torus();
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
        class FactoryTorus : public IFactoryPrimitives {
            public :
                std::unique_ptr<IPrimitives> create();
                std::unique_ptr<IPrimitives> create(ConfigPrimitive);
        };
    }
}
