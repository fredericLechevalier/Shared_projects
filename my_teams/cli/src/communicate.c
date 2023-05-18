/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../includes/client.h"

static void read_socket(connect_t *con)
{
    char *buf = malloc(4096);
    int readed;
    readed = read(con->socket, buf, 4095);
    if (readed == 0) {
        free_con(con);
        free(buf);
        printf("Server shutdown\n");
        exit(0);
    }
    buf[readed] = 0;
    con->res = cjson_parse_obj_str(buf);
    if (con->res == NULL) {
        unknow_response();
    } else {
        char *tmp = cjson_get_by_key(con->res, "status");
        con->status = atoi(tmp);
        free(tmp);
        free(buf);
    }
}

static void write_socket(connect_t *con)
{
    char *out = cjson_get_obj_str(con->command, false);
    write(con->socket, out, my_strlen(out));
    cjson_free(con->command);
    free(out);
    con->command = NULL;
}

void communicate(connect_t *con)
{
    if (FD_ISSET(con->socket, &con->readfd)) {
        read_socket(con);
    }
    if (con->command != NULL) {
        if (FD_ISSET(con->socket, &con->writefd)) {
            write_socket(con);
        }
        return;
    }
}
