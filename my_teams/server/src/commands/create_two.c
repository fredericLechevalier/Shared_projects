/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/server.h"

void create_the_reply(char **args, client_t *client, connect_t *con)
{
    char *body = decode_str(args[0]);
    char *uuid_loc[3] = {client->teams_context, client->channel_context,
    client->thread_context};
    cjson *out = create_reply(uuid_loc, body, client->uuid);
    char *thread_uuid = cjson_get_by_key(out, "uuid");
    char *timestamp = cjson_get_by_key(out, "timestamp");
    client->res = cjson_push(NULL, 6, "status", STR_REPLY_CREATED, "body",
    body, "user_uuid", client->uuid, "timestamp", timestamp, "uuid",
    thread_uuid, "team_uuid", client->teams_context);
    char *datas[4] = {thread_uuid, client->teams_context, body, client->uuid};
    pings_users_reply(client, con, datas);
    cjson_free(out);
    server_event_reply_created(client->thread_context, client->uuid, body);
    free(body);free(timestamp);free(thread_uuid);
}

bool check_users(char *user_uuid, char *team_uuid)
{
    char **users = get_team_subs(team_uuid);
    for (int i = 0; users[i]; ++i) {
        char *tmp = decode_str(users[i]);
        cjson *tmp_obj = cjson_parse_obj_str(tmp);
        free(tmp);
        char *tmp_uuid = cjson_get_by_key(tmp_obj, "uuid");
        cjson_free(tmp_obj);
        if (my_strcomp(user_uuid, tmp_uuid)) {
            free(tmp_uuid);
            cjson_free_array(users);
            return true;
        }
        free(tmp_uuid);
    }
    cjson_free_array(users);
    return false;
}
