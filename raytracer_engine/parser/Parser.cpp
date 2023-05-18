/*
** EPITECH PROJECT, 2022
** B-OOP-400-MLH-4-1-raytracer-theotime.schmeltz
** File description:
** Parser.cpp
*/

#include "Parser.hpp"

RayTracer::Parser::Parser(std::string configFile)
{
    this->error = std::make_unique<Error>("logs.txt");
    this->readConfig(configFile);
}

template<typename T>
T RayTracer::Parser::getSetting(std::string settingsName)
{
    try {
        return T(config.lookup(settingsName));
    } catch (libconfig::SettingNotFoundException &e) {
        this->error->writeLogs("No " + settingsName + " setting in configuration file.\n");
        return (T(NULL));
    } catch (libconfig::SettingTypeException &e) {
        if (typeid(T).hash_code() == typeid(int).hash_code())
            this->error->writeLogs("Type of " + settingsName + " must be an int.\n");
        if (typeid(T).hash_code() == typeid(std::string).hash_code())
            this->error->writeLogs("Type of " + settingsName + " must be a string.\n");
        if (typeid(T).hash_code() == typeid(float).hash_code())
            this->error->writeLogs("Type of " + settingsName + " must be a float.\n");
        if (typeid(T).hash_code() == typeid(double).hash_code())
            this->error->writeLogs("Type of " + settingsName + " must be a double.\n");
        return (T(NULL));
    }
    return (T(NULL));
}

void RayTracer::Parser::readConfig(std::string configFile)
{
    try {
        config.readFile(configFile.c_str());
    } catch (libconfig::FileIOException &e) {
        std::cerr << "Could not read file : " << configFile << std::endl;
        exit(84);
    } catch (libconfig::ParseException &e) {
        std::cerr << "Parse error at " << e.getFile() << ":" << e.getLine() << " - " << e.getError() << std::endl;
        exit(84);
    }
    this->initCamera();
    this->initLights();
    this->initPrimitives();
    this->initOtherFiles();
}

void RayTracer::Parser::initCamera()
{
    Math::Point3d cameraOrigin(this->getSetting<int>("camera.position.x"),
    this->getSetting<int>("camera.position.y"),
    this->getSetting<int>("camera.position.z"));

    RayTracer::Rectangle3d cameraScreen(
    Math::Point3d(this->getSetting<int>("camera.origin.x"), this->getSetting<int>("camera.origin.y"), this->getSetting<int>("camera.origin.z")),
    Math::Vector3d(this->getSetting<int>("camera.resolution.width"), 0, 0),
    Math::Vector3d(0, this->getSetting<int>("camera.resolution.height"), 0));
    
    this->camera = RayTracer::Camera(cameraOrigin, cameraScreen);
}

template<typename T>
T RayTracer::Parser::getSetting(std::string settingsName, const libconfig::Setting &setting, const std::string errorSupp)
{
    try {
        return T(setting.lookup(settingsName));
    } catch (libconfig::SettingNotFoundException &e) {
        this->error->writeLogs("No " + settingsName + " setting in configuration file" + errorSupp + ".\n");
        return (T(NULL));
    } catch (libconfig::SettingTypeException &e) {
        if (typeid(T).hash_code() == typeid(int).hash_code())
            this->error->writeLogs("Type of " + settingsName + " must be an int" + errorSupp + ".\n");
        if (typeid(T).hash_code() == typeid(std::string).hash_code())
            this->error->writeLogs("Type of " + settingsName + " must be a string" + errorSupp + ".\n");
        if (typeid(T).hash_code() == typeid(float).hash_code())
            this->error->writeLogs("Type of " + settingsName + " must be a float" + errorSupp + ".\n");
        if (typeid(T).hash_code() == typeid(double).hash_code())
            this->error->writeLogs("Type of " + settingsName + " must be a double" + errorSupp + ".\n");
        return (T(NULL));
    }
    return (T(NULL));
}

void RayTracer::Parser::initPrimitives()
{
    this->initPlanes();
    this->initSpheres();
    this->initCylinder();
    this->initCone();
}

void RayTracer::Parser::initLights()
{
    this->initDirectionals();
    this->initAmbients();
}

void RayTracer::Parser::initOtherFiles(void)
{
    try {
        const libconfig::Setting &scenes = this->config.getRoot()["parameters"]["scenes"];
        int scenesLen = scenes.getLength();
        for (int i = 0; i < scenesLen; ++i) {
            libconfig::Setting &scene = scenes[i];
            std::string tmpFileName = this->getSetting<std::string>("fileName", scene);
            try {
                config.readFile(tmpFileName.c_str());
            } catch (libconfig::FileIOException &e) {
                std::cerr << "Warning : Could not read second scene : " << tmpFileName << std::endl;
                return;
            } catch (libconfig::ParseException &e) {
                std::cerr << "Warning : In second scene : Parse error at " <<
                e.getFile() << ":" << e.getLine() << " - " << e.getError() << std::endl;
                return;
            }
            this->initLights();
            this->initPrimitives();
        }
    } catch (const libconfig::SettingNotFoundException &e) {
        return;
    }
}

void RayTracer::Parser::initCone()
{
    std::string e = " for cone ";
    try {
        const libconfig::Setting &cones = this->config.getRoot()["primitives"]["cones"];
        int conesLen = cones.getLength();
        for (int i = 0; i < conesLen; ++i) {
            const libconfig::Setting &cone = cones[i];
            Math::Point3d conePos(this->getSetting<int>("position.x", cone, e + std::to_string(i + 1)),
            this->getSetting<int>("position.y", cone, e + std::to_string(i + 1)),
            this->getSetting<int>("position.z", cone, e + std::to_string(i + 1)));
            Math::Vector3d coneColor(this->getSetting<int>("color.r", cone, e + std::to_string(i + 1)),
            this->getSetting<int>("color.g", cone, e + std::to_string(i + 1)),
            this->getSetting<int>("color.b", cone, e + std::to_string(i + 1)));
            double coneRadius = this->getSetting<double>("radius", cone, e + std::to_string(i + 1));
            double coneHeight = this->getSetting<double>("height", cone, e + std::to_string(i + 1));

            RayTracer::Primitives::ConfigPrimitive tmpPush("cone");
            tmpPush.color = coneColor;
            tmpPush.point3d = conePos;
            tmpPush.a = coneRadius;
            tmpPush.x = coneHeight;
            this->primitives.push_back(tmpPush);
        }
    } catch (const libconfig::SettingNotFoundException &e) {
        return;
    }
}

void RayTracer::Parser::initPlanes()
{
    std::string e = " for plane ";
    try {
        const libconfig::Setting &planes = this->config.getRoot()["primitives"]["planes"];
        int planesLen = planes.getLength();
        for (int i = 0; i < planesLen; ++i) {
            const libconfig::Setting &plane = planes[i];
            Math::Vector3d planeColor(this->getSetting<int>("color.r", plane, e + std::to_string(i + 1)),
            this->getSetting<int>("color.g", plane, e + std::to_string(i + 1)),
            this->getSetting<int>("color.b", plane, e + std::to_string(i + 1)));
            Math::Point3d planeOrigin(this->getSetting<int>("origin.x", plane, e + std::to_string(i + 1)),
            this->getSetting<int>("origin.y", plane, e + std::to_string(i + 1)),
            this->getSetting<int>("origin.z", plane, e + std::to_string(i + 1)));
            Math::Vector3d planeNormal(this->getSetting<int>("normal.x", plane, e + std::to_string(i + 1)),
            this->getSetting<int>("normal.y", plane, e + std::to_string(i + 1)),
            this->getSetting<int>("normal.z", plane, e + std::to_string(i + 1)));


            RayTracer::Primitives::ConfigPrimitive tmpPush("plane");
            tmpPush.point3d = planeOrigin;
            tmpPush.vector3d = planeNormal;
            tmpPush.color = planeColor;
            this->primitives.push_back(tmpPush);
        }
    } catch (const libconfig::SettingNotFoundException &e) {
        return;
    }
}

void RayTracer::Parser::initAmbients()
{
    try {
        double tmpAmbient = double(this->config.lookup("lights.ambient"));
        RayTracer::Lights::ConfigLights tmpPush("ambient");
        tmpPush.origin = Math::Point3d(0, 0, 0);
        tmpPush.vector = Math::Vector3d(0, 0, 0);
        tmpPush.color = Math::Vector3d(tmpAmbient, tmpAmbient, tmpAmbient);
        this->lights.push_back(tmpPush);
    } catch (libconfig::SettingNotFoundException &e) {
        return;
    }
}

void RayTracer::Parser::initDirectionals()
{
    std::string e = " for directional light ";
    try {
        const libconfig::Setting &directionals = this->config.getRoot()["lights"]["directional"];
        int directionalsLen = directionals.getLength();
        for (int i = 0; i < directionalsLen; ++i) {
            const libconfig::Setting &directional = directionals[i];
            Math::Point3d directionalOrigin(this->getSetting<int>("point.x", directional, e + std::to_string(i + 1)),
            this->getSetting<int>("point.y", directional, e + std::to_string(i + 1)),
            this->getSetting<int>("point.z", directional, e + std::to_string(i + 1)));
            Math::Vector3d directionalDirection(this->getSetting<int>("direction.x", directional, e + std::to_string(i + 1)),
            this->getSetting<int>("direction.y", directional, e + std::to_string(i + 1)),
            this->getSetting<int>("direction.z", directional, e + std::to_string(i + 1)));
            Math::Vector3d directionalColor(this->getSetting<int>("color.r", directional, e + std::to_string(i + 1)),
            this->getSetting<int>("color.g", directional, e + std::to_string(i + 1)),
            this->getSetting<int>("color.b", directional, e + std::to_string(i + 1)));

            RayTracer::Lights::ConfigLights tmpPush("directional");
            tmpPush.origin = directionalOrigin;
            tmpPush.vector = directionalDirection;
            tmpPush.color = directionalColor;
            this->lights.push_back(tmpPush);
        }
    } catch (const libconfig::SettingNotFoundException &e) {
        return;
    }
}

void RayTracer::Parser::initSpheres()
{
    std::string e = " for sphere ";
    try {
        const libconfig::Setting &spheres = this->config.getRoot()["primitives"]["spheres"];
        int spheresLen = spheres.getLength();
        for (int i = 0; i < spheresLen; ++i) {
            const libconfig::Setting &sphere = spheres[i];
            Math::Point3d sphereOrigin(this->getSetting<int>("x", sphere, e + std::to_string(i + 1)),
            this->getSetting<int>("y", sphere, e + std::to_string(i + 1)),
            this->getSetting<int>("z", sphere, e + std::to_string(i + 1)));
            double sphereRadius = this->getSetting<float>("r", sphere, e + std::to_string(i + 1));
            Math::Vector3d sphereColor(this->getSetting<int>("color.r", sphere, e + std::to_string(i + 1)),
            this->getSetting<int>("color.g", sphere, e + std::to_string(i + 1)),
            this->getSetting<int>("color.b", sphere, e + std::to_string(i + 1)));
            
            RayTracer::Primitives::ConfigPrimitive tmpPush("sphere");
            tmpPush.point3d = sphereOrigin;
            tmpPush.a = sphereRadius;
            tmpPush.color = sphereColor;
            this->primitives.push_back(tmpPush);
        }
    } catch (const libconfig::SettingNotFoundException &e) {
        return;
    }
}

void RayTracer::Parser::initCylinder()
{
    std::string e = " for cylinder ";
    try {
        const libconfig::Setting &cylinders = this->config.getRoot()["primitives"]["cylinder"];
        int cylinderLen = cylinders.getLength();
        for (int i = 0; i < cylinderLen; ++i) {
            const libconfig::Setting &cylinder = cylinders[i];
            Math::Point3d cylinderOrigin(this->getSetting<int>("origin.x", cylinder, e + std::to_string(i + 1)),
            this->getSetting<int>("origin.y", cylinder, e + std::to_string(i + 1)),
            this->getSetting<int>("origin.z", cylinder, e + std::to_string(i + 1)));
            double cylinderRadius = this->getSetting<float>("r", cylinder, e + std::to_string(i + 1));
            Math::Vector3d color(this->getSetting<int>("color.r", cylinder, e + std::to_string(i + 1)),
            this->getSetting<int>("color.g", cylinder, e + std::to_string(i + 1)),
            this->getSetting<int>("color.b", cylinder, e + std::to_string(i + 1)));
            double height = this->getSetting<double>("height", cylinder, e + std::to_string(i + 1));
            RayTracer::Primitives::ConfigPrimitive tmpPush("cylinder");
            tmpPush.point3d = cylinderOrigin;
            tmpPush.a = cylinderRadius;
            tmpPush.color = color;
            tmpPush.height = height;
            this->primitives.push_back(tmpPush);
        }
    } catch (const libconfig::SettingNotFoundException &e) {
        return;
    }
}

std::vector<RayTracer::Primitives::ConfigPrimitive> &RayTracer::Parser::getPrimitives()
{
    return this->primitives;
}

RayTracer::Camera &RayTracer::Parser::getCamera()
{
    return this->camera;
}

std::vector<RayTracer::Lights::ConfigLights> &RayTracer::Parser::getLights()
{
    return this->lights;
}

int RayTracer::Parser::getThreads()
{
    try {
        const libconfig::Setting &params = this->config.getRoot()["parameters"];
        int threads = this->getSetting<int>("threads", params);
        return threads;
    } catch (const libconfig::SettingNotFoundException &e) {
        return 1;
    }
}