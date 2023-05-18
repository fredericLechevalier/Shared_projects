/*
** EPITECH PROJECT, 2023
** FTP
** File description:
** FTP
*/

#include "../../includes/server.h"

static bool set_channel(client_t *client, char *uuid, char *team_uuid)
{
    cjson *channel = get_channel(team_uuid, uuid);
    if (channel == NULL) {
        client->res = cjson_push(NULL, 2, "status", STR_UNKNOWN_TEAM, "uuid",
        uuid);
        return false;
    }
    cjson_free(channel);
    if (client->channel_context != NULL)
        free(client->channel_context);
    client->channel_context = my_strdup(uuid);
    return true;
}

static bool set_thread(client_t *client, char *uuid, char *team_uuid ,
char *channel_uuid)
{
    cjson *thread = get_thread(team_uuid, channel_uuid, uuid);
    if (thread == NULL) {
        client->res = cjson_push(NULL, 2, "status", STR_UNKNOWN_TEAM, "uuid",
        uuid);
        return false;
    }
    cjson_free(thread);
    if (client->thread_context != NULL)
        free(client->thread_context);
    client->thread_context = my_strdup(uuid);
    return true;
}

static bool set_team(client_t *client, char *uuid)
{
    cjson *team = get_team(uuid);
    if (team == NULL) {
        client->res = cjson_push(NULL, 2, "status", STR_UNKNOWN_TEAM, "uuid",
        uuid);
        return false;
    }
    cjson_free(team);
    if (client->teams_context != NULL)
        free(client->teams_context);
    client->teams_context = my_strdup(uuid);
    return true;
}

static char **get_uuid(client_t *client)
{
    char *str_args = cjson_get_by_key(client->req, "args");
    char **args = cjson_parse_array(str_args);
    free(str_args);
    char **out = malloc(sizeof(char *) * 4);
    (args[0] != NULL) ? (out[0] = decode_str(args[0])) : (out[0] = NULL);
    (args[0] != NULL && args[1] != NULL) ? (out[1] = decode_str(args[1])) :
    (out[1] = NULL);
    (out[1] != NULL && args[2] != NULL) ? (out[2] = decode_str(args[2])) :
    (out[2] = NULL);
    out[3] = NULL;
    cjson_free_array(args);
    return out;
}

int use(client_t *client, char *command)
{
    if (!my_strcomp(command, "use"))return 0;if (!check_auth(client))
return 1;char **args = get_uuid(client);if (args == NULL)return 1;free(client
->teams_context); free(client->channel_context);free(client->thread_context);
client->teams_context = NULL;client->channel_context = NULL;client->
thread_context = NULL;if (args[0] != NULL) {
        cjson *team = get_team(args[0]);if (team == NULL) {
            client->res = cjson_push(NULL, 2, "status", STR_UNKNOWN_TEAM,
            "uuid", args[0]);cjson_free_array(args);return 1;
        } cjson_free(team);if (!check_users(client->uuid, args[0])) {
            client->res = cjson_push(NULL, 1, "status", STR_UNAUTHORIZED);
            cjson_free_array(args);return 1;
        } if (!set_team(client, args[0])) {
            cjson_free_array(args);return 1;
        }} if (args[1] != NULL) {
        if (!set_channel(client, args[1], args[0])) {
            cjson_free_array(args);return 1;
        }} if (args[2] != NULL) {
        if (!set_thread(client, args[2], args[0], args[1])) {
            cjson_free_array(args);return 1;
        }}cjson_free_array(args);client->res = MAGIC return 1;
}
