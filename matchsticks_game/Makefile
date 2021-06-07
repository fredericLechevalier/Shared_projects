SRC	=			launcher.c 		\
				my_getline.c 	\
				board_maker.c 	\
				game.c 			\
				players_turns.c \
				map_update.c 	\

CFLAGS	+=	-I./include/

OBJ	=	$(SRC:.c=.o)

NAME	=	matchsticks

LIBDIR	=	./lib/my/

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C $(LIBDIR)
		gcc -g -o $(NAME) -I./include/ $(SRC) -L$(LIBDIR) -lmy
		rm *.o

clean:
		rm -f $(OBJ)
		make -C $(LIBDIR) clean

fclean:		clean
		rm -f $(NAME)
		make -C $(LIBDIR) fclean

re:		fclean all
