#pragma once

#include <iostream>
#include <memory>
#include "ConfigPrimitive.hpp"

namespace RayTracer {
    namespace Primitives {
        class IFactoryPrimitives
        {
            public :
                virtual ~IFactoryPrimitives() = default;
                virtual std::unique_ptr<IPrimitives> create(ConfigPrimitive) = 0;
                virtual std::unique_ptr<IPrimitives> create() = 0;
        };
    }
}

