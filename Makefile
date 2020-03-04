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
	$(CC) -o $(NAME_TESTS) $(CPPFLAGS) $(SRC_TESTS) $(LDFLAGS)
	./$(NAME_TESTS)

re: fclean all

.PHONY: all fclean re clean $(NAME) tests_run debug
