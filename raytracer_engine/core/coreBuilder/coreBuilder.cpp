/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-theotime.schmeltz
** File description:
** coreBuilder
*/

#include "coreBuilder.hpp"


RayTracer::coreBuilder::coreBuilder()
{
    this->_core = std::make_unique<core>();
    this->_libs = {};
}

std::string RayTracer::coreBuilder::getFileName(const std::string &name, const std::string &folder)
{
    std::string path("plugins/" + folder);
    for (const auto & entry : std::filesystem::directory_iterator(path)) {
        std::string tmp(entry.path().c_str());
        if (tmp.find(name) != tmp.npos)
            return tmp;
    }
    return "";
}

RayTracer::coreBuilder::coreBuilder(const std::string &fileName)
{
    Parser parser(fileName);
    this->_core = std::make_unique<core>();
    this->_libs = {};
    auto primitives = parser.getPrimitives();
    auto camera = parser.getCamera();
    auto lights = parser.getLights();
    int threads = parser.getThreads();
    this->_core->getNumberOfThreads(threads);
    this->buildCamera(camera);
    for (auto it : primitives)
        this->buildPrimitive(getFileName(it._name, "primitives"), it);
    for (auto it : lights)
        this->buildLight(getFileName(it._name, "lights"), it);
}

RayTracer::coreBuilder::~coreBuilder()
{
    if ((bool)(this->_core))
        this->_core.reset();
    for (void *it : _libs) {
        DLLoader<void> tmp(it);
        tmp.close();
    }
}

std::unique_ptr<RayTracer::core> RayTracer::coreBuilder::getCore()
{
    if (!std::filesystem::is_empty("logs.txt"))
        throw(CriticalError("Errors have been detected in config file, see logs.txt for further informations."));
    std::unique_ptr<RayTracer::core> nwCore(this->_core.release());
    this->_core.reset();
    return nwCore;
}

void RayTracer::coreBuilder::reset()
{
    this->_core.reset();
    for (auto it = _libs.begin(); it < _libs.end(); it++) {
        DLLoader<void> loader(*it);
        loader.close();
    }
    _libs.clear();
}

void RayTracer::coreBuilder::buildPrimitive(const std::string &libName, Primitives::ConfigPrimitive arguments)
{
    DLLoader<Primitives::IFactoryPrimitives> loader(libName);
    std::unique_ptr<Primitives::IFactoryPrimitives> factory = loader.getFactory();
    std::unique_ptr<Primitives::IPrimitives> ptrPrim = factory->create(arguments);
    this->_core->addPrimitives(ptrPrim);
    this->_libs.push_back(*loader);
}

void RayTracer::coreBuilder::buildLight(const std::string &libName, Lights::ConfigLights arguments)
{
    DLLoader<Lights::IFactoryLights> loader(libName);
    std::unique_ptr<Lights::IFactoryLights> factory = loader.getFactory();
    std::unique_ptr<Lights::ILights> ptrLight = factory->create(arguments);
    this->_core->addLight(ptrLight);
    this->_libs.push_back(*loader);
}

void RayTracer::coreBuilder::buildCamera(RayTracer::Camera &camera)
{
    std::shared_ptr<RayTracer::Camera> ptrCam = std::make_shared<RayTracer::Camera>(camera);
    this->_core->addCamera(ptrCam);
}
