/*
** EPITECH PROJECT, 2020
** RAM 1
** File description:
** window
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include "my.h"
#include <stdlib.h>

void my_background(struct Game *data)
{
    sfTexture   *background_t;

    background_t = sfTexture_createFromFile("Ressources/pixel_hill.png",
                                                                    NULL);
    data->background_s = sfSprite_create();
    sfSprite_setTexture(data->background_s, background_t, sfTrue);
}





void my_window(struct Game *data)
{
    sfVideoMode     video_mode = {800, 600, 32};

    data->window = sfRenderWindow_create(video_mode, "My_Hunter",
                                            sfDefaultStyle, NULL);
}