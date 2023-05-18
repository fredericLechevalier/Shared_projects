##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

SRC	=	src/cjson/cjson_free.c	\
		src/cjson/cjson_get_by.c	\
		src/cjson/cjson_push.c	\
		src/cjson/cjson_obj_strj.c	\
		src/cjson/cjson_init.c	\
		src/cjson/cjson_obj_array.c	\
		src/cjson/cjson_delete_by.c	\
		src/cjson/cjson_set_by.c	\
		src/cjson/cjson_parse_obj_str.c	\
		src/cjson/cjson_utils.c	\
		src/cjson/cjson_write_file.c	\
		src/cjson/cjson_read_file.c	\
		src/cjson/cjson_array.c		\
		src/cjson/cjson_do_string.c	\
		src/cjson/cjson_array_free.c	\
		src/utils/read_file.c	\
		src/utils/write_file.c	\
		src/utils/my_strlen.c	\
		src/utils/my_strcmp.c	\
		src/utils/my_strdup.c	\
		src/utils/my_strcopy.c	\
		src/utils/my_strcat.c	\
		src/utils/my_print.c	\
		src/utils/my_itoa.c	\
		src/utils/my_atoi.c	\
		src/utils/my_revstr.c	\
		src/utils/my_print_types.c	\
		src/utils/my_fprint.c	\
		src/utils/my_fprint_types.c	\
		src/utils/my_power.c	\
		src/utils/my_index_of.c	\
		src/utils/my_base_to_base.c	\
		src/utils/my_sort.c	\
		src/utils/my_sort_two.c		\
		src/utils/encode_decode.c			\

CFLAGS += -fPIC -Wall -g

OBJ	=	$(SRC:.c=.o)


NAME	=	libmylib.a

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	rm -f $(OBJ)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
