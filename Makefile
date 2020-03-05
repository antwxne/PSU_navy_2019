##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	= 	src/board_creator.c	\
		src/check.c			\
		src/connect.c 		\
		src/com_game.c 		\
		src/error.c			\
		src/game_loop.c 	\
		src/get_intput.c	\
		src/loop.c 			\
		src/loop_bis.c 		\
		src/main.c			\
		src/read.c			\
		src/replace.c		\
		src/signal.c 		\
		src/toucher.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I./include

LDFLAGS	=	-L./lib -lmy

NAME	=	navy

CC	=	gcc

all:	$(NAME)

$(NAME): $(OBJ)
	make -C lib/my/
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

debug:	CFLAGS += -g3
debug:	re

tests_run: SRC += tests/tests_navy.c
tests_run: SRC := $(filter-out src/main.c, $(SRC))
tests_run: NAME := unit_tests
tests_run:
	$(CC) -o $(NAME) $(SRC) $(LDFLAGS) -lcriterion --coverage -I./include
	./$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(NAME_TESTS)
	make fclean -C lib/my/

re: fclean all

.PHONY: all fclean re clean $(NAME) tests_run debug
