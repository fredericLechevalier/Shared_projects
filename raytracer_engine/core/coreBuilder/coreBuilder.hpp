/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-theotime.schmeltz
** File description:
** coreBuilder
*/

#pragma once

#include "../core.hpp"
#include "DlLoader.hpp"
#include "../../parser/Parser.hpp"
#include <filesystem>

namespace RayTracer {
    class coreBuilder {
        public : 
            coreBuilder();
            coreBuilder(const std::string &);
            ~coreBuilder();
            void buildLight(const std::string &, Lights::ConfigLights);
            void buildPrimitive(const std::string &, Primitives::ConfigPrimitive);
            void buildCamera(RayTracer::Camera &);
            void reset();
            std::unique_ptr<core> getCore();
        private :
            std::string getFileName(const std::string &, const std::string &);
            std::unique_ptr<core> _core;
            std::vector<void *> _libs;
    };
}

// void RayTracer::coreBuilder::buildLights(const std::string &libName, T arguments)
// {
//     DLLoader<Lights::IFactoryLights<T>> loader(libName);
//     Lights::IFactoryLights<T> factory = loader.getFactory();
//     this->_core->addLight(factory.create(arguments));
//     this->_libs.push_back(*loader);
// }

