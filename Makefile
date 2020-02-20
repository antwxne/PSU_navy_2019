##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	= 	src/main.c		\
		src/board_creator.c	\
		src/replace.c		\
		src/read.c		\
		src/error.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I./include

LDFLAGS	=	-L./lib -lmy

NAME	=	navy

SRC_TESTS	=

FLAGS_TESTS	=	-lcriterion --coverage

NAME_TESTS	=	unit_tests

CC	=	gcc

all:	$(NAME)

$(NAME): $(OBJ)
	make -C lib/my/
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

debug:	CFLAGS += -g3
debug:	re

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(NAME_TESTS)
	make fclean -C lib/my/

tests_run:
	make -C lib/my/
	$(CC) -o $(NAME_TESTS) $(SRC_TESTS) $(CPPFLAGS) $(FLAGS_TESTS) $(LDFLAGS)
	./$(NAME_TESTS)

re: fclean all

.PHONY: all fclean re clean $(NAME) tests_run debug
