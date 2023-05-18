/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/server.h"

static void create_the_team(char **args, client_t *client, connect_t *con)
{
    char *name = decode_str(args[0]);
    cjson *test_team = get_team_by_name(name);
    if (test_team != NULL) {
        client->res = cjson_push(NULL, 1, "status", STR_ALREADY_EXIST);
        cjson_free(test_team);free(name);return;
    }
    char *description = decode_str(args[1]);
    cjson *out = create_team(name, description);
    char *uuid = cjson_get_by_key(out, "uuid");
    client->res = cjson_push(NULL, 4, "status", STR_TEAM_CREATED, "uuid",
    uuid, "name", name, "description", description);
    for (int i = 0; i < con->max_client; ++i) {
        if (con->clients[i].uuid != NULL && my_strcomp(con->clients[i].uuid,
        client->uuid) == false)
            con->clients[i].res = cjson_push(NULL, 4, "status",
            STR_EVENT_TEAM_CREATED, "uuid",  uuid, "name", name,
            "description", description);
    }
    cjson_free(out);server_event_team_created(uuid, name, client->uuid);
    free(name);free(description);free(uuid);
}

static void create_the_channel(char **args, client_t *client, connect_t *con)
{
    char *name = decode_str(args[0]);
    cjson *test_channel = get_channel_by_name(client->teams_context ,name);
    if (test_channel != NULL) {
        client->res = cjson_push(NULL, 1, "status", STR_ALREADY_EXIST);
        cjson_free(test_channel);free(name);return;
    }
    char *description = decode_str(args[1]);
    cjson *out = create_channel(client->teams_context, name, description);
    char *uuid = cjson_get_by_key(out, "uuid");
    client->res = cjson_push(NULL, 4, "status", STR_CHANNEL_CREATED, "uuid",
    uuid, "name", name, "description", description);
    char *datas[3] = {uuid, name, description};
    ping_users_channel(client, con, datas);
    cjson_free(out);
    server_event_channel_created(client->teams_context, uuid, name);
    free(name);
    free(description);
    free(uuid);
}

static void create_the_thread(char **args, client_t *client, connect_t *con)
{
    char *title = decode_str(args[0]);
    cjson *test_thread = get_thread_by_title(client->teams_context,
    client->channel_context, title);
    if (test_thread != NULL) {
        client->res = cjson_push(NULL, 1, "status", STR_ALREADY_EXIST);
        cjson_free(test_thread);free(title);return;
    }
    char *body = decode_str(args[1]);
    char *uuid_loc[2] = {client->teams_context, client->channel_context};
    cjson *out = create_thread(uuid_loc, title, body, client->uuid);
    char *uuid = cjson_get_by_key(out, "uuid");
    char *timestamp = cjson_get_by_key(out, "timestamp");
    client->res = cjson_push(NULL, 6, "status", STR_THREAD_CREATED, "uuid",
    uuid , "user_uuid", client->uuid, "timestamp", timestamp, "title", title,
    "body", body);
    char *datas[5] = {uuid, title, body, timestamp, client->uuid};
    pings_users_thread(client, con, datas);
    server_event_thread_created(client->channel_context, uuid, client->uuid ,
    title, body);
    cjson_free(out);free(title);free(body);free(uuid);free(timestamp);
}

static char **parse_args(client_t *client)
{
    char *str_args = cjson_get_by_key(client->req, "args");
    char **args = cjson_parse_array(str_args);
    free(str_args);
    if ((args == NULL || args[0] == NULL || args[1] == NULL) &&
    client->thread_context == NULL) {
        client->res = cjson_push(NULL, 2,"status", STR_BAD_REQUEST, "message",
        "Missing args");
        cjson_free_array(args);
        return NULL;
    }
    if (client->thread_context != NULL && (args == NULL || args[0] == NULL)) {
        client->res = cjson_push(NULL, 2,"status", STR_BAD_REQUEST, "message",
        "Missing args");
        cjson_free_array(args);
        return NULL;
    }
    return args;
}

int create(client_t *client, connect_t *con, char *command)
{
    if (!my_strcomp(command, "create"))return 0;
    if (!check_auth(client)) return 1;
    char **args = parse_args(client);bool pass = false;
    if (args == NULL) return 1;
    if (client->teams_context == NULL) {
        create_the_team(args, client, con);pass = true;
    } else {
        if (!check_users(client->uuid, client->teams_context)) {
            client->res = cjson_push(NULL, 1, "status", STR_UNAUTHORIZED);
            pass = true;
        }
    } if (client->channel_context == NULL && pass == false) {
        create_the_channel(args, client, con);pass = true;
    } if (client->thread_context == NULL && pass == false) {
        create_the_thread(args, client, con);pass = true;
    } if (client->thread_context != NULL && pass == false)
        create_the_reply(args, client, con);
    cjson_free_array(args);
    return 1;
}
