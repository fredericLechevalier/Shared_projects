/*
** EPITECH PROJECT, 2023
** B-OOP-400-MLH-4-1-raytracer-theotime.schmeltz
** File description:
** core
*/

#include "core.hpp"

RayTracer::core::core()
{
    this->_lights.clear();
    this->_primitives.clear();
    this->_threads = 1;
}

RayTracer::core::~core()
{
    for (auto it = this->_lights.begin(); it != this->_lights.end(); it++)
        it->reset();
    for (auto it = this->_primitives.begin(); it != this->_primitives.end(); it++)
        it->reset();
}

Math::Vector3d RayTracer::core::normalizeRGB(Math::Vector3d &color)
{
    Math::Vector3d res = color;
    if (res.x < 0)
        res.x = 0;
    if (res.y < 0)
        res.y = 0;
    if (res.z < 0)
        res.z = 0;
    if (res.x > 255)
        res.x = 255;
    if (res.y > 255)
        res.y = 255;
    if (res.z > 255)
        res.z = 255;
    return (res);
}

bool RayTracer::core::lightHit(int lightIndex, const Math::Point3d &point, int primIndex)
{
    Math::Point3d lightOrigin(this->_lights[lightIndex]->getOrigin());
    RayTracer::Ray lightRay(point, Math::Vector3d(lightOrigin.x - point.x, lightOrigin.y - point.y, lightOrigin.z - point.z));
    int count = 0;
    for (int i = 0; i != this->_primitives.size(); ++i)
        if (i != primIndex && this->_primitives[i]->hits(lightRay))
            return (false);
    return (true);
}

Math::Vector3d RayTracer::core::ambientLights(const Ray &ray, int primIndex, const Math::Point3d &point)
{
    Math::Vector3d res = _primitives[primIndex]->getColor();
    int touched = 0;
    for (int i = 0; i != this->_lights.size(); ++i) {
        if (this->_lights[i]->getDirection().x == 0
        && this->_lights[i]->getDirection().y == 0 && this->_lights[i]->getDirection().z == 0) {
            res.x *= this->_lights[i]->getColor().x;
            res.y *= this->_lights[i]->getColor().x;
            res.z *= this->_lights[i]->getColor().x;
            ++touched;
        }
    }
    for (int i = 0; i != this->_lights.size(); ++i) {
        if (this->lightHit(i, point, primIndex)) {
            Math::Vector3d L = this->_lights[0]->getDirection();
            double k = L.dot(this->_primitives[primIndex]->getNormal(point));
            Math::Vector3d C(k * this->_lights[0]->getColor().x, k * this->_lights[0]->getColor().y, k * this->_lights[0]->getColor().z);
            res += C;
            ++touched;
        }
    }
    if (touched == 0)
        return (Math::Vector3d(10, 10, 10));
    return (this->normalizeRGB(res));
}

void RayTracer::core::addLight(std::unique_ptr<Lights::ILights> &light)
{
    this->_lights.push_back(std::move(light));
}

void RayTracer::core::addPrimitives(std::unique_ptr<Primitives::IPrimitives> &primitive)
{
    this->_primitives.push_back(std::move(primitive));
}

void RayTracer::core::addCamera(std::shared_ptr<RayTracer::Camera> cam)
{
    this->_cam = std::make_shared<RayTracer::Camera> (*cam);
}

void RayTracer::core::write_color_file(Math::Vector3d vector, std::ofstream &file)
{
    file << std::to_string(int(vector.x)) << " " << std::to_string(int(vector.y)) << " " << std::to_string(int(vector.z)) << "\n";
}

Math::Vector3d RayTracer::core::background(double t, double start, double end)
{
    double blue = 255.0;
    double gradient = (1.0 - t) * start + t * end;
    if (gradient < 0)
        gradient = 0;
    if (gradient > 255)
        gradient = 255;
    return Math::Vector3d(0, 0, 0);
}

void RayTracer::core::putpixel(int x, int y, const Math::Vector3d &color, sf::RenderWindow &window)
{
    sf::RectangleShape pixel(sf::Vector2f(1, 1));
    sf::Color myColor;
    myColor.r = color.x;
    myColor.g = color.y;
    myColor.b = color.z;
    myColor.a = 255;

    pixel.setFillColor(myColor);
    pixel.setPosition(x, y);
    window.draw(pixel);
}

void RayTracer::core::writeSFML(void)
{
    double ask_x = this->_cam->screen.bottom_side.lenght() * 10;
    double ask_y = this->_cam->screen.left_side.lenght() * 10;
    sf::RenderWindow window(sf::VideoMode(ask_x, ask_y), "RayTracer");
    std::vector<int> hitPrimitives;
    double tmpMin;
    int primIndex;
    window.clear();
    for (double x = 0; x < ask_x; ++x) {
        for (double y = 0; y < ask_y; ++y) {
            tmpMin = 10000;
            primIndex = -1;
            double u = x / ask_x;
            double v = y / ask_y;
            RayTracer::Ray r = _cam->ray(u, v);
            for (int i = 0; i != _primitives.size(); ++i) {
                if (_primitives[i]->hits(r))
                    hitPrimitives.push_back(i);
            }
            for (int i = 0; i != hitPrimitives.size(); ++i)
                if (i == 0 || tmpMin > _primitives[hitPrimitives[i]]->getRoot(r)) {
                    tmpMin = _primitives[hitPrimitives[i]]->getRoot(r);
                    primIndex = hitPrimitives[i];
                }
            if (primIndex != -1) {
                Math::Point3d test(r.point.x + r.vector.x * _primitives[primIndex]->getRoot(r), r.point.y + r.vector.y * _primitives[primIndex]->getRoot(r), r.point.z + r.vector.z * _primitives[primIndex]->getRoot(r));
                this->putpixel(x, y, this->ambientLights(r, primIndex, test), window);
            } else
                this->putpixel(x, y, Math::Vector3d(0, 0, 0), window);
            hitPrimitives.clear();
        }
    }
    while (window.isOpen()) {
        std::this_thread::sleep_for(std::chrono::microseconds(100000));
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();
        window.display();
    }
}

void RayTracer::core::threadSplit(double nb, double ask_x, double ask_y, double start_x, std::shared_ptr<std::list<std::string>> toFill)
{
    double tmpMin;
    int primIndex;
    std::vector<int> hitPrimitives;
    for (double x = start_x; x < ask_x; ++x) {
        for (double y = 0; y < ask_y; ++y) {
            tmpMin = 10000;
            primIndex = -1;
            double u = y / ask_y;
            double v = x / nb;
            RayTracer::Ray r = _cam->ray(u, v);
            for (int i = 0; i != _primitives.size(); ++i) {
                if (_primitives[i]->hits(r))
                    hitPrimitives.push_back(i);
            }
            for (int i = 0; i != hitPrimitives.size(); ++i) {
                double root = _primitives[hitPrimitives[i]]->getRoot(r);
                if (i == 0 || tmpMin > root) {
                    tmpMin = root;
                    primIndex = hitPrimitives[i];
                }
            }
            if (primIndex != -1) {
                double root = _primitives[primIndex]->getRoot(r);
                Math::Point3d test(r.point.x + r.vector.x * root, r.point.y + r.vector.y * root, r.point.z + r.vector.z * root);
                toFill->push_back(write_color_str(this->ambientLights(r, primIndex, test)));
            } else
                toFill->push_back("0 0 0\n");
            hitPrimitives.clear();
        }
    }
}

void RayTracer::core::writePPM(const std::string & fileName)
{
    double ask_x = this->_cam->screen.bottom_side.lenght() * 10;
    double ask_y = this->_cam->screen.left_side.lenght() * 10;
    std::ofstream file;
    file.open(fileName + ".ppm");
    if (!file)
        throw (CriticalError("No file or cannot open file " + fileName + ".ppm"));
    file << "P3\n" << std::to_string(int(ask_x)) << " " << std::to_string(int(ask_y)) << "\n255\n";
    double NbThreads = static_cast<double> (this->_threads);
    std::list<std::pair<std::thread, std::shared_ptr<std::list<std::string>>>> threads = {};
    for (double actual = 0.0; actual < ask_x; actual += ask_x / NbThreads) {
        std::shared_ptr<std::list<std::string>> tmpList = std::make_shared<std::list<std::string>>();
        std::thread tmp(&RayTracer::core::threadSplit, this, ask_x, actual + ask_x / NbThreads, ask_y, actual, tmpList);
        threads.push_back(std::make_pair<std::thread, std::shared_ptr<std::list<std::string>>>(std::move(tmp), std::move(tmpList)));
    }
    for (auto it = threads.begin(); it != threads.end(); it++) {
        it->first.join();
        for (auto j : *it->second)
            file << j;
    }
    file.close();
}

void RayTracer::core::write_color_cout(Math::Vector3d vector)
{
    std::cout << std::to_string(int(vector.x)) << " " << std::to_string(int(vector.y)) << " " << std::to_string(int(vector.z)) << "\n";
}

std::string RayTracer::core::write_color_str(Math::Vector3d vector)
{
    std::string tmp("");
    tmp += std::to_string(int(vector.x)) + " " + std::to_string(int(vector.y)) + " " + std::to_string(int(vector.z)) + "\n";
    return tmp;
}

void RayTracer::core::writeCout()
{
    double ask_x = this->_cam->screen.bottom_side.lenght() * 10;
    double ask_y = this->_cam->screen.left_side.lenght() * 10;
    std::cout << "P3\n" << std::to_string(int(ask_x)) << " " << std::to_string(int(ask_y)) << "\n255\n";
    double NbThreads = static_cast<double> (this->_threads);
    std::list<std::pair<std::thread, std::shared_ptr<std::list<std::string>>>> threads = {};
    for (double actual = 0.0; actual < ask_x; actual += ask_x / NbThreads) {
        std::shared_ptr<std::list<std::string>> tmpList = std::make_shared<std::list<std::string>>();
        std::thread tmp(&RayTracer::core::threadSplit, this, ask_x, actual + ask_x / NbThreads, ask_y, actual, tmpList);
        threads.push_back(std::make_pair<std::thread, std::shared_ptr<std::list<std::string>>>(std::move(tmp), std::move(tmpList)));
    }
    for (auto it = threads.begin(); it != threads.end(); it++) {
        it->first.join();
        for (auto j : *it->second)
            std::cout << j;
    }
}

void RayTracer::core::getNumberOfThreads(int number)
{
    const auto maxThreads = std::thread::hardware_concurrency();
    if (number >= 0) {
        if (number > maxThreads && maxThreads > 0)
            this->_threads = maxThreads;
        else
            this->_threads = number;
    }
}
