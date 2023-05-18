/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/server.h"

static void apply_res_reply(client_t *client, connect_t *con, char **datas,
char *uuid)
{
    for (int i = 0; i < con->max_client; ++i) {
        if (con->clients[i].uuid != NULL && my_strcomp(con->clients[i].uuid,
        client->uuid) == false && my_strcomp(con->clients[i].uuid, uuid))
            con->clients[i].res = cjson_push(NULL, 6, "status",
            STR_EVENT_REPLY_CREATED, "uuid",  datas[0], "team_uuid", datas[1],
            "body", datas[2], "user_uuid", datas[3]);
    }
}

void pings_users_reply(client_t *client, connect_t *con, char **datas)
{
    char **users = get_team_subs(client->teams_context);
    for (int i = 0; users[i]; ++i) {
        char *tmp = decode_str(users[i]);
        cjson *tmp_obj = cjson_parse_obj_str(tmp);
        free(tmp);
        char *tmp_uuid = cjson_get_by_key(tmp_obj, "uuid");
        cjson_free(tmp_obj);
        apply_res_reply(client, con, datas, tmp_uuid);
        free(tmp_uuid);
    }
    cjson_free_array(users);
}
