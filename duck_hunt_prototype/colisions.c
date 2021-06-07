/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myrunner-frederic.lechevalier
** File description:
** colisions
*/

#include "my.h"
#include <stdlib.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <stdio.h>

int is_coll_between(sfIntRect RA, sfVector2f PA, sfVector2i PB)
{
    int x_coll = 0;
    int y_coll = 0;

    if (PB.x >= PA.x && PA.x + RA.width >= PB.x)
        x_coll++;
    if (PB.y >= PA.y && PA.y + RA.height >= PB.y)
        y_coll++;
    if (x_coll != 0 && y_coll != 0)
        return (1);
    else
        return (0);
}

void collisions_check(struct Game *data)
{
    sfVector2i localPosition = sfMouse_getPositionRenderWindow(data->window);

    if (is_coll_between(
    data->duck1->rect, data->duck1->position, localPosition) == 1) {
        data->duck1->duck_alive = 0;
    }
}