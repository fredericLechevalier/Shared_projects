##
## EPITECH PROJECT, 2023
## project
## File description:
## Makefile
##

SRC	=	main.cpp	\
		Camera/Camera.cpp	\
		core/core.cpp	\
		core/coreBuilder/coreBuilder.cpp	\
		parser/Parser.cpp

NAME = raytracer

CXXFLAGS += -std=c++20 -g

BEFORE_FLAGS = `pkg-config --libs libconfig++`

FLAGS = -ldl -rdynamic -fno-gnu-unique -lconfig++ -lsfml-system -lsfml-graphics -lsfml-window -pthread

OBJ	=	$(SRC:.cpp=.o)

all : $(NAME)

$(NAME):	$(OBJ)
	 g++ $(BEFORE_FLAGS) -o $(NAME) $(OBJ) $(FLAGS)
	 make -C primitives
	 make -C lights

clean	: 
	rm -f $(OBJ)
	 make clean -C primitives
	 make clean -C lights
	

fclean	:	clean
	rm -f $(NAME)
	make clean -C primitives
	make clean -C lights
	rm -f plugins/primitives/*.so
	rm -f plugins/lights/*.so

re:	fclean all

.PHONY:	all lights relights clean fclean re primitives
