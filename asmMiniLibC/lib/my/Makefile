##
## EPITECH PROJECT, 2023
## $NAME_OF_THE_PROJECT
## File description:
## No file there, just an epitech header example .
##

SRC		=	memcpy.asm \
			memmov.asm \
			memset.asm \
			strcasecmp.asm \
			strchr.asm \
			strcmp.asm \
			strlen.asm \
			strncmp.asm \
			strrchr.asm \

OBJ        =     $(SRC:.asm=.o)

LFLAGS    =    -L./ -lasm

NAME     =    libasm.so

%.o: %.asm
		nasm -f elf64 $<

all: $(OBJ)
		ld -fPIC -shared $(OBJ) -o $(NAME)

clean:
		rm -f $(OBJ)
		rm -f *.o

fclean:		clean
		rm -f $(NAME)

re:		fclean all
