/*
** EPITECH PROJECT, 2023
** FTP
** File description:
** FTP
*/

#include "../../includes/server.h"

static void add_the_message(cjson *message_obj, char *uuid, char *message)
{
    char *messages_str = cjson_get_by_key(message_obj, "messages");
    char **messages = cjson_parse_array(messages_str);free(messages_str);
    int len = 0;
    for (;messages[len] != NULL; ++len);
    messages = realloc(messages, sizeof(char *) * (len + 2));
    char *timestamp = my_itoa((int)time(NULL));
    char *tmp = cjson_do_string(3, "uuid", uuid, "message", message,
"timestamp", timestamp);
    free(timestamp);
    messages[len] = encode_str(tmp);free(tmp);
    messages[len + 1] = NULL;
    char *array_str = cjson_stringify_array(messages);cjson_free_array(
messages);
    cjson_set_by_key(message_obj, "messages", array_str);free(array_str);
}

static char *create_mp(char *dest, char *uuid, char *message)
{
    char **messages = malloc(sizeof(char *) * 2);
    char *timestamp = my_itoa((int)time(NULL));
    char *tmp = cjson_do_string(3, "uuid", uuid, "message", message,
"timestamp", timestamp);free(timestamp);
    messages[0] = encode_str(tmp);free(tmp);messages[1] = NULL;
    char *array_str = cjson_stringify_array(messages);cjson_free_array(
messages);char *out = cjson_do_string(2, "uuid", dest, "messages", array_str);
    free(array_str);
    return out;
}

static void put_the_message(cjson *user,char *dest, char *uuid, char *message)
{
    char *messages_str = cjson_get_by_key(user, "messages");
    if (!messages_str) messages_str = strdup("[]");
    char **messages = cjson_parse_array(messages_str);free(messages_str);
    cjson *tmp_message; char *tmp_message_str; char *tmp_uuid;
    bool found = false;char *tmp_str_out;int i = 0;
    for (; messages[i]; ++i) {
        tmp_message_str = decode_str(messages[i]); tmp_message =
cjson_parse_obj_str(tmp_message_str);free(tmp_message_str);tmp_uuid =
cjson_get_by_key(tmp_message, "uuid");
        if (my_strcomp(tmp_uuid, dest)) {
            found = true;add_the_message(tmp_message, uuid, message);free(
messages[i]);tmp_str_out = cjson_get_obj_str(tmp_message, false);messages[i]
= encode_str(tmp_str_out);free(tmp_str_out);
        }free(tmp_uuid);cjson_free(tmp_message);
    } if (!found) {
        tmp_str_out = create_mp(dest, uuid, message);messages = realloc(
messages, sizeof(char *) * (i + 2));messages[i] = encode_str(tmp_str_out);
        messages[i + 1] = NULL;free(tmp_str_out);
    } messages_str = cjson_stringify_array(messages);cjson_set_by_key(user,
"messages", messages_str);free(messages_str);cjson_free_array(messages);
}

static void rewrite_file(char **users, cjson *file, int me_index,
cjson *tmp_user_obj)
{
    void *tmp_swap = users[me_index];
    char *tmp_user = cjson_get_obj_str(tmp_user_obj, false);
    users[me_index] = encode_str(tmp_user);
    free(tmp_swap);
    cjson_free(tmp_user_obj);
    free(tmp_user);
    char *users_str = cjson_stringify_array(users);
    cjson_free_array(users);
    cjson_set_by_key(file, "users", users_str);
    cjson_write_file("server.cjson", O_TRUNC, file);
    free(users_str);
    cjson_free(file);
}

bool update_messages(char *my_uuid, char *uuid, char *message)
{
    cjson *file = cjson_read_file("server.cjson", BUFFER_SIZE);char *users_str
= cjson_get_by_key(file, "users");char **users = cjson_parse_array(users_str);
free(users_str);char *tmp_user; cjson *tmp_user_obj; char *tmp_uuid; bool
found = false; int me_index = -1;
    for (int i = 0; users[i] != NULL; ++i) {
        tmp_user = decode_str(users[i]);tmp_user_obj = cjson_parse_obj_str
(tmp_user);free(tmp_user);tmp_uuid = cjson_get_by_key(tmp_user_obj, "uuid");
        if (my_strcomp(tmp_uuid, my_uuid)) me_index = i;
        if (my_strcomp(tmp_uuid, uuid)) {
            found = true; put_the_message(tmp_user_obj, my_uuid, my_uuid,
message);free(users[i]);tmp_user = cjson_get_obj_str(tmp_user_obj, false);
        users[i] = encode_str(tmp_user);free(tmp_user);
        }free(tmp_uuid);cjson_free(tmp_user_obj);
    }
    if (!found || me_index == -1) {
        cjson_free_array(users); cjson_free(file);return false;
    }
    tmp_user = decode_str(users[me_index]);tmp_user_obj = cjson_parse_obj_str
(tmp_user);free(tmp_user);put_the_message(tmp_user_obj, uuid, my_uuid,
message); rewrite_file(users, file, me_index, tmp_user_obj);return true;
}
