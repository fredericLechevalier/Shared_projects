/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myrunner-frederic.lechevalier
** File description:
** window
*/

#include "my.h"
#include "project.h"
#include <stdlib.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>

void update_rect_bg(struct Game *data)
{
    if (data->BG_1->RectBG.left >= data->BG_1->RectBG.width)
        data->BG_1->RectBG.left -= data->BG_1->RectBG.width;
    data->BG_1->RectBG.left += data->scrolling_speed;
    if (data->BG_2->RectBG.left >= data->BG_2->RectBG.width)
        data->BG_2->RectBG.left -= data->BG_2->RectBG.width;
    data->BG_2->RectBG.left += data->scrolling_speed / 2;
    if (data->BG_3->RectBG.left >= data->BG_3->RectBG.width)
        data->BG_3->RectBG.left -= data->BG_3->RectBG.width ;
    data->BG_3->RectBG.left += data->scrolling_speed / 4;
}

void create_rectangles_bg(struct Game *data)
{
    data->BG_1->RectBG.top = 0;
    data->BG_1->RectBG.height = 210;
    data->BG_1->RectBG.left = 0;
    data->BG_1->RectBG.width = 2936 / 2;
    data->BG_2->RectBG.top = 0;
    data->BG_2->RectBG.height = 369;
    data->BG_2->RectBG.left = 0;
    data->BG_2->RectBG.width = 2404 / 2;
    data->BG_3->RectBG.top = 100;
    data->BG_3->RectBG.height = 600;
    data->BG_3->RectBG.left = 0;
    data->BG_3->RectBG.width = 1932 / 2;
}

void display_my_window(struct Game *data)
{
    if (data->P1->life == 1)
        update_rect_bg(data);
    data->BG_3->position.x = 0;
    data->BG_3->position.y = 0;
    sfSprite_setTextureRect(data->BG_3->background_s, data->BG_3->RectBG);
    sfSprite_setPosition(data->BG_3->background_s, data->BG_3->position);
    sfRenderWindow_drawSprite(data->window, data->BG_3->background_s, NULL);
    data->BG_2->position.x = 0;
    data->BG_2->position.y = 360;
    sfSprite_setTextureRect(data->BG_2->background_s, data->BG_2->RectBG);
    sfSprite_setPosition(data->BG_2->background_s, data->BG_2->position);
    sfRenderWindow_drawSprite(data->window, data->BG_2->background_s, NULL);
    data->BG_1->position.x = 0;
    data->BG_1->position.y = 570;
    sfSprite_setTextureRect(data->BG_1->background_s, data->BG_1->RectBG);
    sfSprite_setPosition(data->BG_1->background_s, data->BG_1->position);
    sfRenderWindow_drawSprite(data->window, data->BG_1->background_s, NULL);
}

void create_background(struct Game *data)
{
    data->BG_1->background_t = sfTexture_createFromFile(
        "Ressources/ground.jpg",
        NULL);
    data->BG_1->background_s = sfSprite_create();
    sfSprite_setTexture(data->BG_1->background_s, data->BG_1->background_t,
    sfTrue);
    data->BG_2->background_t = sfTexture_createFromFile(
        "Ressources/background_hills_water_2.png",
        NULL);
    data->BG_2->background_s = sfSprite_create();
    sfSprite_setTexture(data->BG_2->background_s, data->BG_2->background_t,
    sfTrue);
    data->BG_3->background_t = sfTexture_createFromFile(
        "Ressources/background_montains.png",
        NULL);
    data->BG_3->background_s = sfSprite_create();
    sfSprite_setTexture(data->BG_3->background_s, data->BG_3->background_t,
    sfTrue);
    create_rectangles_bg(data);
}

void create_window(struct Game *data)
{
    data->scrolling_speed = 15;
    sfVideoMode video_mode = {800, 600, 32};

    data->window = sfRenderWindow_create(video_mode, "My_Hunter",
                                                            sfDefaultStyle,
                                                            NULL);
}