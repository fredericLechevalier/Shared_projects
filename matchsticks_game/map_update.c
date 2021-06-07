/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-matchstick-frederic.lechevalier
** File description:
** map_update
*/

#include "my.h"
#include "project.h"

void map_update(struct Game *data)
{
    int y = (data->lenght + 1) * (data->line_pick + 1);
    for (; data->board[y] != '|'; y--);
    for (int x = 0; x != data->matches_pick; x++, y--)
        data->board[y] = ' ';
    data->matches[data->line_pick - 1] -= data->matches_pick;
}