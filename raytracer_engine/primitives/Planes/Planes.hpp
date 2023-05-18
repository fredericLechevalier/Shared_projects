/*
** EPITECH PROJECT, 2022
** B-OOP-400-MLH-4-1-raytracer-theotime.schmeltz
** File description:
** Planes.hpp
*/

#pragma once
#include "../FactoryPrimitives/IFactoryPrimitives.hpp"

namespace RayTracer
{
    namespace Primitives {
        class Planes : public IPrimitives
        {
            public:
                Planes();
                ~Planes();
                Planes(const Math::Point3d &origin, const Math::Vector3d &normal, const Math::Vector3d &color);
                bool hits(Ray &ray);
                Math::Vector3d getColor(void);
                Math::Point3d getOrigin(void);
                double getRoot(Ray &ray);
                Math::Vector3d getNormal(const Math::Point3d &point);
                void translate(const Math::Vector3d &vector);
                void rotate(double rotate);
                void scale(double scale);
            private:
                Math::Vector3d color;
                Math::Vector3d normal;
                Math::Point3d origin;
        };
        class FactoryPlane : public IFactoryPrimitives {
            public :
                std::unique_ptr<IPrimitives> create();
                std::unique_ptr<IPrimitives> create(ConfigPrimitive);
        };
    }
}
