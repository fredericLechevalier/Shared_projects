/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-matchstick-frederic.lechevalier
** File description:
** board_maker
*/

#include "my.h"
#include "project.h"

void matches_counter(struct Game *data)
{
    data->matches = malloc(sizeof(int *) * (data->lines + 1));
    for (int x = 0; x != data->lines; x++) {
        data->matches[x] = x * 2 + 1;
    }
}

void board_maker(struct Game *data)
{
    int x = 0;

    data->board = my_malloc(data->height * data->lenght + data->lines + 3,'\0');
    for (; x != data->lenght; x++)
        data->board[x] = '*';
    data->board[x] = '\n';
    x++;
    for (int y = 0; y != data->lines; y++, x++) {
        data->board[x] = '*';
        x++;
        x = line_filler(data, y, x);
        data->board[x] = '*';
        x++;
        data->board[x] = '\n';
    }
    for (int a = 0; a != data->lenght; a++, x++)
        data->board[x] = '*';
    data->board[x] = '\n';
    matches_counter(data);
}

int line_filler(struct Game *data, int y, int x)
{
    int sticks = (y * 2 + 1);

    for (int a = 0; a != ((data->lenght - 2 - sticks) / 2); a++, x++)
        data->board[x] = ' ';
    for (int a = 0; a != sticks; a++, x++)
        data->board[x] = '|';
    for (int a = 0; a != ((data->lenght - 2 - sticks) / 2); a++, x++)
        data->board[x] = ' ';
    return (x);
}