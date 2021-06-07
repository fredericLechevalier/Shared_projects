SRC	=	sokoban_main.c		\
		sokoban_ncurses.c 	\
		sokoban_tools.c 	\
		sokoban_movements.c \

CFLAGS	+=	-I./include/

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

LIBDIR	=	./lib/my/

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C $(LIBDIR)
		gcc -g -o $(NAME) -I./include/ $(SRC) -L$(LIBDIR) -lmy -lncurses
		rm *.o

clean:
		rm -f $(OBJ)
		make -C $(LIBDIR) clean

fclean:		clean
		rm -f $(NAME)
		make -C $(LIBDIR) fclean

re:		fclean all
