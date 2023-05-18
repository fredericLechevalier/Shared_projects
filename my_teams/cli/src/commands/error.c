/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/client.h"

static int unknown(connect_t *con)
{
    if (con->status == UNKNOWN_TEAM) {
        char *uuid = cjson_get_by_key(con->res, "uuid");
        client_error_unknown_team(uuid);
        free(uuid);
        return 1;
    }
    if (con->status == UNKNOWN_CHANNEL) {
        char *uuid = cjson_get_by_key(con->res, "uuid");
        client_error_unknown_channel(uuid);
        free(uuid);
        return 1;
    }

    if ( con->status == UNKNOWN_THREAD) {
        char *uuid = cjson_get_by_key(con->res, "uuid");
        client_error_unknown_thread(uuid);
        free(uuid);
        return 1;
    }
    return 0;
}

int error(connect_t *con)
{
    if (con->status == BAD_REQUEST || con->status == NOT_AUTH || con->status
    == ALREADY_AUTH ) {
        char *text = cjson_get_by_key(con->res, "message");
        printf("%s\n", text);free(text);return 1;
    }
    if (con->status == UNKNOWN_USER) {
        char *uuid = cjson_get_by_key(con->res, "uuid");
        client_error_unknown_user(uuid);free(uuid);return 1;
    }
    if (unknown(con))return 1;
    if (con->status == UNAUTHORIZED) {
        client_error_unauthorized();return 1;
    }
    if (con->status == ALREADY_EXIST) {
        client_error_already_exist();return 1;
    }
    return 0;
}

void unknow_response(void)
{
    printf("Unknown server response\n");
}
