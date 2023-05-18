/*
** EPITECH PROJECT, 2023
** FTP
** File description:
** FTP
*/

#include "../includes/server.h"

static void free_cli(client_t *cli)
{
    if (cli->user_name) free(cli->user_name);
    if (cli->uuid) free(cli->uuid);
    if (cli->req) free(cli->req);
    if (cli->res) free(cli->res);
    cli->req = NULL;
    cli->res = NULL;
    cli->user_name = NULL;
    cli->uuid = NULL;
    cli->sock = 0;
}

static int do_handle(connect_t *con, int tmp, int i)
{
    char buffer[4096];
    int readNb;

    if ((readNb = read(tmp , buffer, 4095)) == 0) {
        close(tmp);
        free_cli(con->clients + i);
    } else if (readNb == -1){
        return 84;
    } else {
        buffer[readNb] = 0;
        con->clients[i].req = cjson_parse_obj_str(buffer);
        handle_commands(&con->clients[i], con);
        cjson_free(con->clients[i].req);
        con->clients[i].req = NULL;
    }
    return 0;
}

static void client_write(client_t *client)
{
    char *out = cjson_get_obj_str(client->res, false);
    write(client->sock, out, my_strlen(out));
    cjson_free(client->res);
    free(out);
    client->res = NULL;
}

int handle_client(connect_t *con)
{
    int tmp;

    for (int i = 0; i < con->max_client; ++i) {
        tmp = con->clients[i].sock;
        if (FD_ISSET(tmp, &con->readfds) && do_handle(con, tmp, i) != 0)
            return 84;
        if (FD_ISSET(tmp, &con->writefds) && con->clients[i].res != NULL)
            client_write(con->clients + i);
    }
    return 0;
}
