/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myrunner-frederic.lechevalier
** File description:
** my_runner
*/

#include "my.h"
#include "project.h"
#include <stdlib.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>

unsigned ticking(unsigned tick)
{
    if (tick > 65500)
        tick = 0;
    else
        tick++;
    return (tick);
}

void main()
{
    struct Game *data = malloc(sizeof(struct Game));
    data->BG_1 = malloc(sizeof(struct Background));
    data->BG_2 = malloc(sizeof(struct Background));
    data->BG_3 = malloc(sizeof(struct Background));
    data->P1 = malloc(sizeof(struct Player));
    data->obst_1 = malloc(sizeof(struct Obstacle));
    data->game_over = malloc(sizeof(struct Hud));

    create_window(data);
    launch_game(data);
    sfRenderWindow_destroy(data->window);
    free(data);
}

void launch_game(struct Game *data)
{
    create_background(data);
    create_character(data);
    create_obstacles(data);
    create_huds(data);
    data->tick = 0;
    data->restart = -1;
    GameLoop(data);
}