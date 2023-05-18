/*
** EPITECH PROJECT, 2023
** FTP
** File description:
** FTP
*/

#include "../../includes/server.h"

static char *get_user_messages(char *uuid, char **messages)
{
    for (int i = 0; messages[i]; ++i) {
        char *message_str = decode_str(messages[i]);
        cjson *message = cjson_parse_obj_str(message_str);
        free(message_str);
        char *message_uuid = cjson_get_by_key(message, "uuid");
        if (my_strcomp(message_uuid, uuid)) {
            char *messages_str = cjson_get_by_key(message, "messages");
            cjson_free(message);
            cjson_free_array(messages);
            free(message_uuid);
            return messages_str;
        }
        free(message_uuid);
        cjson_free(message);
    }
    cjson_free_array(messages);
    return strdup("[]");
}

static char *get_messages(char *uuid, char *my_uuid)
{
    cjson *users = cjson_read_file("server.cjson", BUFFER_SIZE);
    char *users_str = cjson_get_by_key(users, "users");
    char **users_array = cjson_parse_array(users_str);
    free(users_str);cjson_free(users);
    for (int i = 0; users_array[i] != NULL; ++i) {
        char *user_str = decode_str(users_array[i]);
        cjson *user = cjson_parse_obj_str(user_str);free(user_str);
        char *user_uuid = cjson_get_by_key(user, "uuid");
        if (my_strcomp(user_uuid, my_uuid)) {
            char *messages_str = cjson_get_by_key(user, "messages");
            char **messages = cjson_parse_array(messages_str);
            free(messages_str);
            cjson_free_array(users_array);
            free(user_uuid);cjson_free(user);
            return get_user_messages(uuid, messages);
        }
        free(user_uuid);cjson_free(user);
    }
    cjson_free_array(users_array);
    return NULL;
}

static char **parse_args(client_t *client)
{
    char *args_str = cjson_get_by_key(client->req, "args");
    char **args = cjson_parse_array(args_str);
    free(args_str);
    if (args == NULL || args[0] == NULL) {
        client->res = cjson_push(NULL, 2,"status", STR_BAD_REQUEST, "message",
        "Missing paramaters");
        cjson_free_array(args);
        return NULL;
    }
    return args;
}

int messages(client_t *client, char *command)
{
    if (!my_strcomp(command, "messages"))
        return 0;
    if (!check_auth(client)) return 1;
    char **args = parse_args(client);
    if (args == NULL)
        return 1;
    char *uuid = decode_str(args[0]);
    cjson *tmp = get_user_by_uuid(uuid);
    if (tmp == NULL) {
        client->res = cjson_push(NULL, 2, "status", STR_UNKNOWN_USER, "uuid",
        uuid);free(uuid);cjson_free_array(args);return 1;
    }
    cjson_free(tmp);
    cjson_free_array(args);
    char *messages = get_messages(uuid, client->uuid);
    if (messages != NULL) {
        client->res = cjson_push(NULL, 2,"status", STR_MESSAGES,
        "messages", messages);free(messages);
    }
    free(uuid);return 1;
}
