/*
** EPITECH PROJECT, 2022
** Test
** File description:
** main.cpp
*/

#include "parser/Parser.hpp"
#include <SFML/Graphics.hpp>
#include "core/coreBuilder/coreBuilder.hpp"

static void handleCore(std::string fileName, int av, char **ar)
{
    if (fileName.compare("--help") == 0) {
        std::cout << "USAGE: ./raytracer <SCENE_FILE> <sfml>\n\n  SCENE_FILE: scene configuration\n  sfml: optional argument to specify the use of sfml to draw the scene" << std::endl;
        return;
    }
    try {
        RayTracer::coreBuilder build(fileName);
        std::unique_ptr<RayTracer::core> core = build.getCore();
        if (av == 3) {
            if (std::strstr(ar[2], "sfml") != NULL)
                core->writeSFML();
            else
                core->writePPM(ar[2]);
        } else
            core->writeCout();
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return;
    }
    return;
}

static int handleMain(int av, char **ar)
{
    std::string configFile;
    if (av < 2 || av > 4) {
        std::cerr << "Invalid number of argument, use --help for usage." << std::endl;
        return 84;
    }
    configFile = ar[1];
    handleCore(configFile, av, ar);
    return 0;
}

int main(int av, char **ar)
{
    return handleMain(av, ar);
}

