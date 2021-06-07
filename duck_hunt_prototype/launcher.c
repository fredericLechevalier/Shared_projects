/*
** EPITECH PROJECT, 2020
** RAM 1
** File description:
** launcher
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include "my.h"
#include <stdlib.h>
#include <stdio.h>

int my_strcomp(char *a, char *b)
{
    int nb = 0;

    for (;a[nb] != '\0'; nb++)
        if (a[nb] != b[nb])
            return (0);
    if (a[nb] == b[nb])
            return (1);
    return (0);
}

unsigned ticking(unsigned tick)
{
    if (tick > 65500)
        tick = 0;
    else
        tick++;
    return (tick);
}

void check_input(struct Game *data)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(data->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(data->window);
        if (event.type == sfEvtMouseButtonPressed)
            collisions_check(data);
    }
}

void GameLoop(struct Game *data)
{
    data->tick = 0;
    sfRenderWindow_setFramerateLimit(data->window, 30);
    while (sfRenderWindow_isOpen(data->window)) {
        check_input(data);
        sfRenderWindow_drawSprite(data->window, data->background_s, NULL);
        createEnemy(data);
        update_sprite(data);
        data->tick = ticking(data->tick);
        sfRenderWindow_display(data->window);
    }
    sfRenderWindow_destroy(data->window);
}

int main(int argc, char **argv)
{
    if (argc == 2) {
        if (my_strcomp(argv[1], "-h") == 1)
        my_putstr("Welcome to the 'my_hunter' game !\nHere you can click with your mouse on flying ducks on the screen to shoot them as long as you wish !\n\0");
        return (0);
    }
    struct Game *data = malloc(sizeof(struct Game));
    data->duck1 = malloc(sizeof(struct Enemy));

    my_window(data);
    my_background(data);
    duck_int(data);
    data->duck1->duck_alive = 0;
    GameLoop(data);
}