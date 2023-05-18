##
## EPITECH PROJECT, 2023
## RayTracer core
## File description:
## makefile for core in the raytracer
##

SRC	=	core.cpp	\
		coreBuilder/coreBuilder.cpp

NAME	=	core

OBJ	=	$(SRC:.cpp=.o)

all:	$(NAME)

CXXFLAGS += -std=c++20

FLAGS = -ldl -rdynamic -fno-gnu-unique

$(NAME):	$(OBJ)
	 g++ -g -o $(NAME) $(OBJ) $(FLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all