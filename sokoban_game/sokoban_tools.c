/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-frederic.lechevalier
** File description:
** sokoban_tools
*/

#include "my.h"
#include "project.h"

void check_win(struct Game *data)
{
    int x = 0;

    if (data->c == ' ')
        data->map->board = my_strcpy_map(data->map->board, data->map->original_board);
    for (; data->map->original_board[x] != '\0'; x++) {
        if (data->map->original_board[x] == '+' && data->map->board[x] != 'o')
            return;
    }
    data->game_running = 2;
}

void check_Os(struct Game *data)
{
    int x = 0;
    for (;data->map->original_board[x] != '\0'; x++) {
        if (data->map->original_board[x] == '+' && data->map->board[x] == ' ')
            data->map->board[x] = '+';
    }
}

int check_window_stats(struct Game *data)
{
    getmaxyx(stdscr, data->screen->height, data->screen->width);
    if (data->screen->height < data->map->height)
        return (1);
    if (data->screen->width < data->map->width)
        return (1);
    return (0);
}

char *my_strcpy_map(char *dest, char const *src)
{
    int a = 0;
    int b = 0;

    while (src[a] != '\0') {
        dest[b] = src[a];
        a++;
        b++;
    }
    dest[a] = '\0';
    return (dest);
}