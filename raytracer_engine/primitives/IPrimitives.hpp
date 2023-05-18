#pragma once

#include <exception>
#include <iostream>
#include "../maths/Vector3d.hpp"
#include "../maths/Point3d.hpp"
#include "../maths/Ray.hpp"

namespace RayTracer {
    namespace Primitives {

        class IPrimitives
        {
            public:
                virtual bool hits(Ray &ray) = 0;
                virtual Math::Vector3d getColor(void) = 0;
                virtual Math::Point3d getOrigin(void) = 0;
                virtual double getRoot(Ray &ray) = 0;
                virtual Math::Vector3d getNormal(const Math::Point3d &point) = 0;
                virtual void translate(const Math::Vector3d &vector) = 0;
                virtual void rotate(double rotate) = 0;
                virtual void scale(double scale) = 0;
        };
    }
}