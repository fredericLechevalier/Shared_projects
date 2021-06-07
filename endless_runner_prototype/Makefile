SRC	=		launcher.c		\
			my_runner.c		\
			window.c		\
			character.c 	\
			obstacle.c		\
			colisions.c 	\
			huds.c 			\

CFLAGS	+=	-I./include/

SFML = -lcsfml-graphics -lcsfml-system -lcsfml-window -lm

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

LIBDIR	=	./lib/my/

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C $(LIBDIR)
		gcc -g -o $(NAME) -I./include/ $(SRC) -L$(LIBDIR) -lmy $(SFML)
		rm *.o

clean:
		rm -f $(OBJ)
		make -C $(LIBDIR) clean

fclean:		clean
		rm -f $(NAME)
		make -C $(LIBDIR) fclean

re:		fclean all
