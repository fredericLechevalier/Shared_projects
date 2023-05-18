/*
** EPITECH PROJECT, 2022
** B-OOP-400-MLH-4-1-raytracer-theotime.schmeltz
** File description:
** Parser.hpp
*/

#pragma once
#include "../lights/FactoryLights/ConfigLights.hpp"
#include "../Camera/Camera.hpp"
#include "../core/Error.hpp"
#include "../core/CriticalError.hpp"
#include <fstream>
#include <iostream>
#include <libconfig.h++>
#include <libconfig.h>
#include <vector>

namespace RayTracer
{
    class Parser
    {
    public:
        Parser(std::string configFile);
        ~Parser() {};
        void readConfig(std::string configFile);
        template<typename T>
        T getSetting(std::string settingsName);
        template<typename T>
        T getSetting(std::string settingsName, const libconfig::Setting &setting, const std::string errorSupp = "");
        std::vector<RayTracer::Primitives::ConfigPrimitive> &getPrimitives();
        std::vector<RayTracer::Lights::ConfigLights> &getLights();
        Camera &getCamera();
        int getThreads();
    protected:
        void initCamera(void);
        void initLights(void);
        void initPrimitives(void);
        void initSpheres(void);
        void initPlanes(void);
        void initAmbients(void);
        void initDirectionals(void);
        void initCylinder(void);
        void initCone(void);
        void initOtherFiles(void);
        libconfig::Config config;
        std::vector<RayTracer::Lights::ConfigLights> lights;
        std::vector<RayTracer::Primitives::ConfigPrimitive> primitives;
        Camera camera;
        std::unique_ptr<Error> error;
    };
}
