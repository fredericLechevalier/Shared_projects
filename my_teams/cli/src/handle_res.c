/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../includes/client.h"

static void do_handle_res(connect_t *con)
{
    int tot = 0;
    tot += login(con) + logout(con) + connection(con);
    tot += help(con);
    tot += error(con);
    tot += users(con);
    tot += user(con);
    tot += messages(con);
    tot += nothing(con);
    tot += list(con);
    tot += subscribe(con);
    tot += unsubscribe(con);
    tot += info(con);
    tot += create(con);
    tot += received(con);
    tot += other_login(con);
    tot += other_logout(con);
    tot += event_create(con);
    if (tot == 0)
        unknow_response();
}

void handle_res(connect_t *con)
{
    if (con->res != NULL) {
        do_handle_res(con);
        cjson_free(con->res);
        con->res = NULL;
    }
}
