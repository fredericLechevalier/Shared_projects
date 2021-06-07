/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-frederic.lechevalier
** File description:
** sokoban_movements
*/

#include "my.h"
#include "project.h"

void move_testD(struct Game *data)
{
    if (data->map->board[data->plyr->pos + 1] != '#') {
        if (data->map->board[data->plyr->pos + 1] == ' '
        || data->map->board[data->plyr->pos + 1] == '+') {
            data->map->board[data->plyr->pos] = ' ';
            data->map->board[data->plyr->pos + 1] = 'A';
        } else if (data->map->board[data->plyr->pos + 1] == 'o'
        && data->map->board[data->plyr->pos + 2] == ' '
        || data->map->board[data->plyr->pos + 2] == '+') {
            data->map->board[data->plyr->pos] = ' ';
            data->map->board[data->plyr->pos + 1] = 'A';
            data->map->board[data->plyr->pos + 2] = 'o';
        }
    }
}

void move_testQ(struct Game *data)
{
    if (data->map->board[data->plyr->pos - 1] != '#') {
        if (data->map->board[data->plyr->pos - 1] == ' '
        || data->map->board[data->plyr->pos - 1] == '+') {
            data->map->board[data->plyr->pos] = ' ';
            data->map->board[data->plyr->pos - 1] = 'A';
        } else if (data->map->board[data->plyr->pos - 1] == 'o'
        && data->map->board[data->plyr->pos - 2] == ' '
        || data->map->board[data->plyr->pos - 2] == '+') {
            data->map->board[data->plyr->pos] = ' ';
            data->map->board[data->plyr->pos - 1] = 'A';
            data->map->board[data->plyr->pos - 2] = 'o';
        }
    }
}

void move_testZ(struct Game *data)
{
    int X = data->map->width;
    if (data->map->board[data->plyr->pos - X - 1] != '#') {
        if (data->map->board[data->plyr->pos - X - 1] == ' '
        || data->map->board[data->plyr->pos - X - 1] == '+') {
            data->map->board[data->plyr->pos] = ' ';
            data->map->board[data->plyr->pos - X - 1] = 'A';
        } else if (data->map->board[data->plyr->pos - X - 1] == 'o'
        && data->map->board[data->plyr->pos - 2*X - 2] == ' '
        || data->map->board[data->plyr->pos - 2*X - 2] == '+') {
            data->map->board[data->plyr->pos] = ' ';
            data->map->board[data->plyr->pos - X - 1] = 'A';
            data->map->board[data->plyr->pos - 2*X - 2] = 'o';
        }
    }
}

void move_testS(struct Game *data)
{
    int X = data->map->width;
    if (data->map->board[data->plyr->pos + X + 1] != '#') {
        if (data->map->board[data->plyr->pos + X + 1] == ' '
        || data->map->board[data->plyr->pos + X + 1] == '+') {
            data->map->board[data->plyr->pos] = ' ';
            data->map->board[data->plyr->pos + X + 1] = 'A';
        } else if (data->map->board[data->plyr->pos + X + 1] == 'o'
        && data->map->board[data->plyr->pos + 2*X + 2] == ' '
        || data->map->board[data->plyr->pos + 2*X + 2] == '+') {
            data->map->board[data->plyr->pos] = ' ';
            data->map->board[data->plyr->pos + X + 1] = 'A';
            data->map->board[data->plyr->pos + 2*X + 2] = 'o';
        }
    }
}