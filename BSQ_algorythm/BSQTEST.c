/*
** EPITECH PROJECT, 2020
** RAM 1
** File description:
** BSQTEST
*/

#include <unistd.h>
#include "include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int lowest_nbr(char *map, int *board, int i)
{
    int answer;
    int nb1 = board[i-1];
    int nb2;
    int nb3;
    int y = 0;

    for (; map[y] != '\n'; y++);
    y++;
    nb2 = board[i-y];
    nb3 = board[i-y-1];
    answer = nb1;
    if (answer > nb2)
        answer = nb2;
    if (answer > nb3)
        answer = nb3;
    return (answer);
}

int *algo(char *map, int *board, int i)
{
    if (map[i] == 'o' || map[i] == '\n')
        board[i] = 0;
    else
        board[i] = 1 + lowest_nbr(map, board, i);
    return (board);
}

void scaning_step1(char *map, int *board)
{
    int square_size = 0;
    int position = 0;
    int i = 0;

    for (; map[i] != '\n' && map[i] != '\0'; i++) {
        if (square_size == 0 && map[i] == '.') {
                square_size = 1;
                position = i;
                board[i] = 1;
        } else if (map[i] == '.') {
            board[i] = 1;
        } else
            board[i] = 0;
    }
    board[i] = 0;
    for (; map[i] != '\0'; i++) {
        board = algo(map, board, i);
        if (board[i] > square_size) {
            square_size = board[i];
            position = i;
        }
    }
    replacing(map, square_size, position);
}

int bsq_read(char *filepath, int fd, int i)
{
    int bytes_read;
    char *buffer = my_malloc(i+1, '\0');
    char *map = my_malloc(i+1, '\0');
    int board[i];

    bytes_read = read(fd, buffer, i);
    if (bytes_read == -1)
        return (84);
    map = my_strcpy_map(map, buffer);
    bytes_read = is_map_legit(bytes_read, map, buffer);
    if (bytes_read == -1)
        return (84);
    scaning_step1(map, board);
    free(buffer);
    free(map);
    close (fd);
    return (0);
}

int main(int argc, char **argv)
{
    char *filepath = argv[1];
    int fd = open(filepath, O_RDONLY);
    int i = 0;
    int error = 0;
    struct stat data;

    fstat(fd, &data);
    i = data.st_size;
    error = bsq_read(filepath,fd, i);
    if (error == 84)
        return (84);
}