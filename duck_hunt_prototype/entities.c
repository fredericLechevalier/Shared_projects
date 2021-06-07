/*
** EPITECH PROJECT, 2020
** RAM 1
** File description:
** entities
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include "my.h"
#include <stdlib.h>
#include <SFML/Window.h>
#include <stdio.h>

void update_sprite(struct Game *data)
{
    if (data->duck1->duck_alive == 1) {
        data->duck1->position.x += 16;
        data->duck1->position.y += 2;
        if (data->duck1->rect.left > 130 && data->tick % 4 == 0) {
            data->duck1->rect.left = 0;
        } else if (data->tick % 4 == 0) {
            data->duck1->rect.left += data->duck1->rect.width;
        }
        sfSprite_setPosition(data->duck1->duck_s, data->duck1->position);
        sfSprite_setTextureRect(data->duck1->duck_s, data->duck1->rect);
        sfRenderWindow_drawSprite(data->window, data->duck1->duck_s, NULL);
    }
}

void createEnemy (struct Game *data)
{
    if (data->duck1->position.x > 875 || data->duck1->duck_alive == 0) {
        data->duck1->duck_alive = 1;
        data->duck1->position.x = -120;
        data->duck1->position.y = (rand() % 300);
        sfSprite_setPosition(data->duck1->duck_s, data->duck1->position);
        sfRenderWindow_drawSprite(data->window, data->duck1->duck_s, NULL);
    }
}

void duck_int(struct Game *data)
{
    data->duck1->duck_t = sfTexture_createFromFile("Ressources/duck.png", NULL);
    data->duck1->duck_s = sfSprite_create();
    sfSprite_setTexture(data->duck1->duck_s, data->duck1->duck_t, sfTrue);
    data->duck1->rect.top = 0;
    data->duck1->rect.left = 0;
    data->duck1->rect.height = 100;
    data->duck1->rect.width = 110;
}