##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##




all:
	make -C libs/MyLib
	make -C server
	make template -C server
	mv server/myteams_server .
	make -C cli
	mv cli/myteams_cli .

clean:
	make clean -C libs/MyLib
	make clean -C server
	make clean -C cli

fclean:	clean
	make fclean -C libs/MyLib
	make fclean -C server
	make fclean -C cli
	rm -f myteams_cli
	rm -f myteams_server

re:	fclean all
