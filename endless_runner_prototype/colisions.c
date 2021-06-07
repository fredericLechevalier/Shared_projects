/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myrunner-frederic.lechevalier
** File description:
** colisions
*/

#include "my.h"
#include "project.h"
#include <stdlib.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>

int is_coll_between(sfIntRect RA, sfVector2f PA, sfIntRect RB, sfVector2f PB)
{
    int x_coll = 0;
    int y_coll = 0;
    if (PB.x <= PA.x && PA.x <= PB.x + RB.width)
        x_coll++;
    if (PB.x <= PA.x + RA.width && PA.x + RA.width <= PB.x + RB.width)
        x_coll++;
    if (PB.y <= PA.y && PA.y <= PB.y + RB.height)
        y_coll++;
    if (PB.y <= PA.y + RA.height && PA.y + RA.height <= PB.y + RB.height)
        y_coll++;
    if (x_coll != 0 && y_coll != 0)
        return (1);
    else
        return (0);
}

void collisions_check(struct Game *data)
{
    if (is_coll_between(
    data->P1->rect, data->P1->position,
    data->obst_1->rect, data->obst_1->position) == 1)
        data->P1->life = 0;
}