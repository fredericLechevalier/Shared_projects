/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-theotime.schmeltz
** File description:
** core
*/

#pragma once

#include "../lights/FactoryLights/IFactoryLights.hpp"
#include "../primitives/FactoryPrimitives/IFactoryPrimitives.hpp"
#include "coreBuilder/DlLoader.hpp"
#include "../Camera/Camera.hpp"
#include <vector>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <cstring>
#include <thread>
#include <list>

namespace RayTracer {
    class core {
        public :
            core();
            ~core();
            void addLight(std::unique_ptr<Lights::ILights> &);
            void addPrimitives(std::unique_ptr<Primitives::IPrimitives> &);
            void addCamera(std::shared_ptr<Camera>);
            void getNumberOfThreads(int);
            void writePPM(const std::string &);
            void writeCout();
            void writeSFML(void);
            void putpixel(int x, int y, const Math::Vector3d &color, sf::RenderWindow &window);
        private :
            void threadSplit(double nb, double ask_x, double ask_y, double start_x, std::shared_ptr<std::list<std::string>> toFill);
            bool lightHit(int lightIndex, const Math::Point3d &point, int primIndex);
            void write_color_file(Math::Vector3d vector, std::ofstream &file);
            void write_color_cout(Math::Vector3d vector);
            std::string write_color_str(Math::Vector3d vector);
            Math::Vector3d ambientLights(const Ray &ray, int primIndex, const Math::Point3d &point);
            Math::Vector3d background(double t, double start, double end);
            Math::Vector3d normalizeRGB(Math::Vector3d &color);
            std::vector<std::unique_ptr<Lights::ILights>> _lights;
            std::vector<std::unique_ptr<Primitives::IPrimitives>> _primitives;
            std::shared_ptr<Camera> _cam;
            std::mutex _mutex;
            int _threads;
    };
}