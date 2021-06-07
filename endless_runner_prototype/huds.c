/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myrunner-frederic.lechevalier
** File description:
** huds
*/

#include "my.h"
#include "project.h"
#include <stdlib.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>

void create_game_over(struct Game *data)
{
    data->game_over->texture = sfTexture_createFromFile(
        "Ressources/game_over_2.png",
        NULL);
    data->game_over->sprite = sfSprite_create();
    sfSprite_setTexture(data->game_over->sprite, data->game_over->texture, sfTrue);
    data->game_over->position.x = 260;
    data->game_over->position.y = 150;
}

void create_huds(struct Game *data)
{
    create_game_over(data);
}

void update_huds(struct Game *data)
{
    if (data->P1->life == 0) {
        sfSprite_setPosition(data->game_over->sprite, data->game_over->position);
        sfRenderWindow_drawSprite(data->window, data->game_over->sprite, NULL);
    }
}