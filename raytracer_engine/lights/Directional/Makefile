##
## EPITECH PROJECT, 2022
## B-OOP-400-MLH-4-1-raytracer-theotime.schmeltz
## File description:
## Makefile
##

SRC =	Directional.cpp

NAME	=	directional.so

OBJ	=	$(SRC:.cpp=.o)

all:	$(NAME)

CXXFLAGS += -std=c++20 -fPIC

FLAGS = -shared

$(NAME):	$(OBJ)
	 g++ -g -o $(NAME) $(OBJ) $(FLAGS)
	 mv $(NAME) ../../plugins/lights/

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all