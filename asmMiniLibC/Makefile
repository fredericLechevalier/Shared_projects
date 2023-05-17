##
## EPITECH PROJECT, 2023
## $NAME_OF_THE_PROJECT
## File description:
## You might wanna use LD_PRELOAD=./lib/my/ for assembler, just in case
##

SRC	=		main.c \

##CFLAGS	+=	-I./include/

LDFLAGS	+= -std=gnu17 -Wall -Wextra

OBJ	=	$(SRC:.c=.o)

NAME	=	miniLibC

LIBDIR	=	./lib/my/

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C $(LIBDIR)
		gcc -g -Wl,-rpath=$(LIBDIR) -o $(NAME) $(SRC) -L$(LIBDIR) -lasm
		rm *.o

clean:
		rm -f $(OBJ)
		rm -f *.o
		make -C $(LIBDIR) clean

fclean:		clean
		rm -f $(NAME)
		make -C $(LIBDIR) fclean

re:		fclean all
