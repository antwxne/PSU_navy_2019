/*
** EPITECH PROJECT, 2020
** navy
** File description:
** board_creator
*/

#include <stdlib.h>
#include <stdio.h>
#include "navy.h"
#include "my.h"

static void red (char x)
{
    my_printf("\033[1;31m");
    my_putchar(x);
    my_printf("\033[0m");
}

static void blue (char o)
{
    my_printf("\033[1;36m");
    my_putchar(o);
    my_printf("\033[0m");
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

static char *simple_cat(char *dest, char *src)
{
    int i = 0;

    for (; dest[i] != 0; i++);
    for (int s_i = 0; src[s_i] != 0; s_i++, i++)
        dest[i] = src[s_i];
    dest[i] = 0;
    return (dest);
}

static char *create_line_board(int i)
{
    char *line = malloc(sizeof(char)*18);

    if (line == NULL)
        return (NULL);
    line[0] = '0' - 1 + i;
    line[1] = '|';
    line[2] = '\0';
    line = simple_cat(line, ". . . . . . . .\0");
    return (line);
}

char **create_board(void)
{
    char **board = malloc(sizeof(char *)*11);
    int i = 2;

    if (board == NULL)
        return (NULL);
    board[0] = " |A B C D E F G H\0";
    board[1] = "-+---------------\0";
    for (; i < 10; i++)
        board[i] = create_line_board(i);
    board[i] = NULL;
    return (board);
}
