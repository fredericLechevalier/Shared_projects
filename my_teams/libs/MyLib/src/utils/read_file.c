/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/utils.h"

static char *get_bufs(int fd, int buf_size)
{
    char *buf = malloc(sizeof(char) * buf_size + 1);
    char *final_buf = malloc(sizeof(char));
    int read_ret = buf_size;
    final_buf[0] = 0;

    while (read_ret == buf_size) {
        read_ret = read(fd, buf, buf_size);
        if (buf == NULL)
            return NULL;
        buf[read_ret] = 0;
        final_buf = my_strcat(final_buf, buf);
        buf = malloc(sizeof(char) * buf_size + 1);
    }
    free(buf);
    return final_buf;
}

char *read_file(const char *path, int buf_size)
{
    int fd = open(path, O_RDONLY);
    char * out;

    if (fd == -1)
        return NULL;
    out = get_bufs(fd, buf_size);
    if (out == NULL)
        return NULL;
    close(fd);
    return out;
}
