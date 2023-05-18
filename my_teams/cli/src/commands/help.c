/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/client.h"

int help(connect_t *con)
{
    if (con->status != HELP)
        return 0;
    printf("• /help : show help\n\
• /login [“user_name”] : set the user_name used by client\n• /lo\
gout : disconnect the client from the server\n• /users : get the list of all \
users that exist on the domain\n• /user [“user_uuid”] : get details about t\
he requested user\n• /send [“user_uuid”] [“message_body”] : send a message t\
o specific user\n• /messages [“user_uuid”] : list all messages exchanged wit\
h the specified user\n• /subscribe [“team_uuid”] : subscribe to the events o\
f a team and its sub directories (enable reception of all events from a team\
)\n• /subscribed ?[“team_uuid”] : list all subscribed teams or list all user\
s subscribed to a team\n• /unsubscribe [“team_uuid”] : unsubscribe from a te\
am\n• /use ?[“team_uuid”] ?[“channel_uuid”] ?[“thread_uuid”] : Sets the comm\
and context to a team/channel/thread\n• /create : based on the context, crea\
te the sub resource (see below)\n• /list : based on the context, list all th\
e sub resources (see below)\n• /info : based on the context, display details \
of the current resource (see below)\n");
    return 1;
}
