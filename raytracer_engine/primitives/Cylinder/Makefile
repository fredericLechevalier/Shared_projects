##
## EPITECH PROJECT, 2023
## Cylinder
## File description:
## makefile for Cylinder in raytracer primitives
##

SRC	=	Cylinder.cpp

NAME	=	cylinder.so

OBJ	=	$(SRC:.cpp=.o)

all:	$(NAME)

CXXFLAGS += -std=c++20 -fPIC

FLAGS = -shared

$(NAME):	$(OBJ)
	 g++ -g -o $(NAME) $(OBJ) $(FLAGS)
	 mv $(NAME) ../../plugins/primitives/

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
