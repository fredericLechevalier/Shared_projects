/*
** EPITECH PROJECT, 2022
** Test
** File description:
** main.cpp
*/

#include "../includes/Core.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cout << "You must select a graphical lib" << std::endl;
        return (84);
    }
    Arcade::Core core(av[1]);
    core.loop();
    return (0);
}
