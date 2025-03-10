##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## go go
##

SRC 	=	src/dump.c	\
			src/hash.c	\
			src/my_strcmp.c	\
			src/mini_printf.c	\
			src/util.c	\
			src/delete.c	\
			src/hashtable.c	\
			src/fct_insert.c	\
			src/delete_hashtable.c	\
			src/search.c

OBJ 	= 	$(SRC:.c=.o)

NAME 	=	libhashtable.a

all: 	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

doc:
	doxygen documentation.doxy

tests_run:
	echo "no test"
clean :
	rm -f $(OBJ)
	rm -f *.gcno
	rm -f *.gcda

fclean: clean
	rm -f $(NAME)
	rm -f unit_tests

re : 	fclean all
