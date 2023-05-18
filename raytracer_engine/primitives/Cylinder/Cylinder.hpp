/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-theotime.schmeltz
** File description:
** Cylinder
*/

#pragma once

#include "../IPrimitives.hpp"
#include "../FactoryPrimitives/IFactoryPrimitives.hpp"

namespace RayTracer {
    namespace Primitives {
        class Cylinder : public IPrimitives {
            public:
                Cylinder();
                Cylinder(const Math::Point3d &point, double radius, double h, Math::Vector3d &color);
                ~Cylinder();
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
                Math::Point3d center;
                double height;
                double radius;
        };
        class FactoryCylinder : public IFactoryPrimitives {
            public :
                std::unique_ptr<IPrimitives> create();
                std::unique_ptr<IPrimitives> create(ConfigPrimitive);
        };
    }
}
