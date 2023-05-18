##
## EPITECH PROJECT, 2022
## B-ASM-400-MLH-4-1-asmminilibc-theotime.schmeltz
## File description:
## Makefile
##

SRC	=	src/main.cpp	\
		src/Core.cpp

NAME	=	arcade

all:	$(NAME)

core:	$(OBJ)
		g++ -o $(NAME) $(SRC) -ldl -fno-gnu-unique -g

graphicals:
	g++ -o lib/arcade_ncurses.so src/Graphical/Ncurses.cpp -lncurses -shared -fPIC
	g++ -o lib/arcade_sfml.so src/Graphical/SFML.cpp -shared -fPIC -lsfml-system -lsfml-graphics -lsfml-window
	g++ -o lib/arcade_sdl2.so src/Graphical/Sdl2.cpp -shared -fPIC -lSDL2 -lGL -lSDL2_ttf

games:
	g++ -o lib/arcade_nibbler.so src/Games/Nibbler.cpp -shared -fPIC
	g++ -o lib/arcade_snake.so src/Games/Snake.cpp -shared -fPIC
	g++ -o lib/arcade_centipede.so src/Games/Centipede/*.cpp -shared -fPIC

$(NAME):	core graphicals games

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f lib/*.so

re:	fclean all

.PHONY:        all clean fclean re games graphicals core
