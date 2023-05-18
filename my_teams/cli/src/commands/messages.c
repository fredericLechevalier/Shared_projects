/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/client.h"

int received(connect_t *con)
{
    if (con->status != MESSAGE_RECEIVED)
        return 0;
    char *uuid = cjson_get_by_key(con->res, "uuid");
    char *message = cjson_get_by_key(con->res, "message");
    client_event_private_message_received(uuid, message);
    free(uuid);
    free(message);
    return 1;
}

int messages(connect_t *con)
{
    if (con->status != MESSAGES)
        return 0;
    char *messages_str = cjson_get_by_key(con->res, "messages");
    char **messages = cjson_parse_array(messages_str);
    free(messages_str);
    for (int i = 0; messages[i]; ++i) {
        char *decoded = decode_str(messages[i]);
        cjson *message_obj = cjson_parse_obj_str(decoded);
        free(decoded);
        char *uuid = cjson_get_by_key(message_obj, "uuid");
        char *message = cjson_get_by_key(message_obj, "message");
        char *timestamp = cjson_get_by_key(message_obj, "timestamp");
        client_private_message_print_messages(uuid, atoi(timestamp), message);
        free(uuid);
        free(message);
        free(timestamp);
        cjson_free(message_obj);
    }
    cjson_free_array(messages);
    return 1;
}
