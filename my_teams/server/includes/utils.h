/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#ifndef UTILS_H
    #define UTILS_H
    #define MAGIC cjson_push(NULL, 1, "status", STR_DO_NOTHING);

    #include "server.h"
cjson *get_user_by_username(char *username);
cjson *get_user_by_uuid(char *uuid);
cjson *create_user(char *username);
cjson *get_team(char *uuid);
cjson *get_channel(char *team_uuid, char *uuid);
cjson *get_thread(char *team_uuid, char *channel_uuid, char *uuid);
cjson *create_team(char *name, char *description);
cjson *create_channel(char *team_uuid, char *name, char *description);
cjson *create_thread(char **uuids, char *name, char *description,
char *user_uuid);
cjson *create_reply(char **loc_uuids, char *content, char *user_uuid);
char **get_team_subs(char *uuid);
void ping_users_channel(client_t *client, connect_t *con, char **datas);
void pings_users_thread(client_t *client, connect_t *con, char **datas);
void pings_users_reply(client_t *client, connect_t *con, char **datas);
cjson *get_thread_by_title(char *team_uuid, char *channel_uuid, char *title);
cjson *get_channel_by_name(char *team_uuid, char *name);
cjson *get_team_by_name(char *name);
#endif // !UTILS_H
