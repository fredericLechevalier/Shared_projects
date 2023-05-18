##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

SRC	=	src/main.c		\
		src/args.c		\
		src/connect.c	\
		src/get_command.c	\
		src/handle_res.c	\
		src/communicate.c	\
		src/commands/log.c	\
		src/commands/help.c	\
		src/commands/error.c	\
		src/commands/users.c	\
		src/commands/user.c		\
		src/commands/messages.c	\
		src/commands/nothing.c		\
		src/commands/list.c		\
		src/commands/sub_unsub.c	\
		src/commands/info.c	\
		src/commands/create.c	\
		src/commands/event_create.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-g
FLAGS	=	-L../libs/myteams -lmyteams -L../libs/MyLib -lmylib


NAME	=	myteams_cli

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(FLAGS)
	rm -f $(OBJ)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
