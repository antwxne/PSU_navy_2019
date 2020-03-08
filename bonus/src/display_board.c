/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** display_board
*/

#include <stdlib.h>
#include <my.h>

static void red(char x)
{
    my_putstr("\033[1;31m");
    my_putchar(x);
    my_putstr("\033[0m");
}

static void blue(char o)
{
    my_putstr("\033[1;36m");
    my_putchar(o);
    my_putstr("\033[0m");
}

void display_board(char **board)
{
    int y = 2;

    my_printf("%s\n%s\n", board[0], board[1]);
    for (; board[y] != NULL; y++) {
        for (int x = 0; board[y][x] != 0; x++) {
            if (board[y][x] == 'x')
                red(board[y][x]);
            else if (board[y][x] == 'o')
                blue(board[y][x]);
            else
                my_putchar(board[y][x]);
        }
        my_putchar('\n');
    }
}