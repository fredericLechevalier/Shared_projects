/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-frederic.lechevalier
** File description:
** sokoban
*/

#include "my.h"
#include "project.h"

int file_error(struct Game *data)
{
    for (int x = 0; data->map->original_board[x] != '\0'; x++) {
        if (data->map->original_board[x] != ' '
        && data->map->original_board[x] != '\n'
        && data->map->original_board[x] != 'A'
        && data->map->original_board[x] != 'o'
        && data->map->original_board[x] != '+'
        && data->map->original_board[x] != '#')
            return (0);
    }
    return (1);
}

void file_read(char *filepath, struct Game *data)
{
    char *buffer;
    int bytes_read;
    int fd = open(filepath, O_RDONLY);
    struct stat stats;
    fstat(fd, &stats);
    buffer = my_malloc(stats.st_size, '\0');
    data->map->original_board = my_malloc(stats.st_size, '\0');
    data->map->board = my_malloc(stats.st_size, '\0');
    bytes_read = read(fd, buffer, stats.st_size);
    data->map->original_board = my_strcpy_map(data->map->original_board,
    buffer);
    data->map->board = my_strcpy_map(data->map->board, buffer);
    for (int x = 1; data->map->original_board[x - 1] != '\n'; x++)
        data->map->width = x;
    for (int x = 0; data->map->original_board[x] != '\0'; x++)
        if (data->map->original_board[x] == '\n')
            data->map->height++;
}

int main(int argc, char **argv)
{
    struct Game *data = malloc(sizeof(struct Game));
    data->map = malloc(sizeof(struct Map));
    data->screen = malloc(sizeof(struct Screen));
    data->plyr = malloc(sizeof(struct Player));
    if (argc == 1)
        return (84);
    file_read(argv[1], data);
    if (data->map->board[0] == '0') {
        return (84);
    }
    if (file_error(data) == 0)
        return (84);
    data->game_running = 1;
    keypad(stdscr, TRUE);
    GameLoop(data);
    return (0);
}