/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myrunner-frederic.lechevalier
** File description:
** my_runner
*/

#include "my.h"
#include "project.h"
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>

void check_input(struct Game *data)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(data->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(data->window);
        if (event.type == sfEvtKeyPressed
        && sfKeyboard_isKeyPressed(sfKeySpace)
        && data->P1->Y_speed == (data->P1->const_jump
        + data->P1->const_jump/10))//-44
            data->P1->Y_speed = (data->P1->const_jump * -1);//40
        if (event.type == sfEvtKeyPressed
        && sfKeyboard_isKeyPressed(sfKeyY)
        && data->P1->life == 0)
            data->restart = 1;
        if (event.type == sfEvtKeyPressed
        && sfKeyboard_isKeyPressed(sfKeyN)
        && data->P1->life == 0)
            data->restart = 0;
    }
}

void GameLoop(struct Game *data)
{
    sfRenderWindow_setFramerateLimit(data->window, 30);
    while (sfRenderWindow_isOpen(data->window) && data->restart != 0) {
        check_input(data);
        display_my_window(data);
        update_obstacles(data);
        update_character(data);
        update_huds(data);
        collisions_check(data);
        data->tick = ticking(data->tick);
        sfRenderWindow_display(data->window);
        if (data->restart == 1)
            launch_game(data);
    }
}