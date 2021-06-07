/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myrunner-frederic.lechevalier
** File description:
** obstacle
*/

#include "my.h"
#include "project.h"
#include <stdlib.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>

void create_obstacles(struct Game *data)
{
    data->obst_1->texture = sfTexture_createFromFile(
        "Ressources/spikes_3.png",
        NULL);
    data->obst_1->sprite = sfSprite_create();
    sfSprite_setTexture(data->obst_1->sprite,
    data->obst_1->texture, sfTrue);
    data->obst_1->rect.top = 0;
    data->obst_1->rect.height = 130;
    data->obst_1->rect.left = 0;
    data->obst_1->rect.width = 126 / 2;
    data->obst_1->position.x = 800;
    data->obst_1->position.y = 575 - 135;
    data->obst_1->life = 1;
    data->obst_1->X_speed = -12;
}

void update_obstacles(struct Game *data)
{
    if (data->tick % (data->scrolling_speed * 7) == 0
    && data->P1->life == 1) {
        data->obst_1->life = 1;
        data->obst_1->position.x = 800;
    }
    if (data->obst_1->life == 1) {
        if (data->P1->life == 1)
            data->obst_1->position.x -= data->scrolling_speed;
        sfSprite_setTextureRect(data->obst_1->sprite, data->obst_1->rect);
        sfSprite_setPosition(data->obst_1->sprite, data->obst_1->position);
        sfRenderWindow_drawSprite(data->window, data->obst_1->sprite, NULL);
        if (data->obst_1->position.x <= (data->obst_1->rect.width * -1))
            data->obst_1->life = 0;
    }
}