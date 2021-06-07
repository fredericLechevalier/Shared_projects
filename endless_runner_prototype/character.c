/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myrunner-frederic.lechevalier
** File description:
** character
*/

#include "my.h"
#include "project.h"
#include <stdlib.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>

void jumping(struct Game *data)
{
    data->P1->position.y -= data->P1->Y_speed;
    data->P1->Y_speed += data->P1->const_jump/10;
    data->P1->rect.top = data->P1->rect.height;
}

void create_character(struct Game *data)
{
    data->P1->texture = sfTexture_createFromFile(
        "Ressources/sonic_sprite_sheet_3.png",
        NULL);
    data->P1->sprite = sfSprite_create();
    sfSprite_setTexture(data->P1->sprite, data->P1->texture, sfTrue);
    data->P1->rect.top = 0;
    data->P1->rect.height = 110;
    data->P1->rect.left = 15;
    data->P1->rect.width = 100;
    data->P1->position.x = 50;
    data->P1->position.y = 570 - data->P1->rect.height;
    data->P1->life = 1;
    data->P1->const_jump = -50;
    data->P1->Y_speed = data->P1->const_jump + data->P1->const_jump/10;
}

void update_character(struct Game *data)
{
    if (data->P1->Y_speed != (data->P1->const_jump
    + data->P1->const_jump / 10)
    && data->P1->life != 0)
        jumping(data);
    else
        data->P1->rect.top = 0;
    sfSprite_setTextureRect(data->P1->sprite, data->P1->rect);
    sfSprite_setPosition(data->P1->sprite, data->P1->position);
    sfRenderWindow_drawSprite(data->window, data->P1->sprite, NULL);
    if (data->tick % 5 != 0)
        return;
    if (data->P1->life == 1) {
        if (data->P1->rect.left >= data->P1->rect.width * 3)
            data->P1->rect.left = 15;
        else 
        data->P1->rect.left += data->P1->rect.width;
    } else {
        data->P1->rect.width = 110;
        data->P1->rect.left = 610;
        data->P1->rect.height = 130;
    }
}