SRC	=	my_putstr.c			\
		my_getnbr.c			\
		my_putchar.c		\
		my_putnbr.c			\
		my_strlen.c			\
		my_revstr.c			\
		my_strcpy.c			\
		my_int_to_str.c		\
		my_getnbr_base.c	\
		my_malloc.c 		\

CFLAGS	+=	-I../../include/

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) *.o
		rm *.o

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
