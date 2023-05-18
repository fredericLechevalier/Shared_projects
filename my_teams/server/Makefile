##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

SRC	=	src/main.c		\
		src/args.c		\
		src/connect.c	\
		src/disconnect.c	\
		src/handle_client.c	\
		src/handle_commands.c	\
		src/utils/uuid.c	\
		src/utils/get_user.c	\
		src/utils/create_user.c	\
		src/utils/check_auth.c	\
		src/utils/teams.c	\
		src/utils/channels.c	\
		src/utils/threads.c	\
		src/utils/create_team.c	\
		src/utils/create_channel.c	\
		src/utils/create_thread.c	\
		src/utils/create_reply.c	\
		src/utils/pings.c	\
		src/utils/pings_two.c	\
		src/commands/login.c	\
		src/commands/logout.c	\
		src/commands/help.c		\
		src/commands/error.c	\
		src/commands/users.c	\
		src/commands/user.c		\
		src/commands/send.c		\
		src/commands/send_two.c	\
		src/commands/messages.c	\
		src/commands/use.c		\
		src/commands/create.c	\
		src/commands/list.c		\
		src/commands/create_two.c	\
		src/commands/subscribe.c \
		src/commands/unsubscribe.c \
		src/commands/subscribed.c \
		src/commands/subscribed_two.c \
		src/commands/info.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-g
FLAGS	=	-luuid -L../libs/myteams -lmyteams -L../libs/MyLib -lmylib

NAME	=	myteams_server

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(FLAGS)
	rm -f $(OBJ)

all:	$(NAME)

template:
	gcc template.c $(CFLAGS) -L../libs/MyLib -lmylib
	./a.out
	rm -f a.out

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
