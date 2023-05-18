##
## EPITECH PROJECT, 2023
## Arcade Snake
## File description:
## makefile for sphere in raytracer primitives
##

SRC	=	Sphere.cpp

NAME	=	sphere.so

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