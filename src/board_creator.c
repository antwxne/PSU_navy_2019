/*
** EPITECH PROJECT, 2020
** navy
** File description:
** board_creator
*/

#include <stdlib.h>
#include "navy.h"
#include "my.h"

void display_board(char **board)
{
    for (int i = 0; board[i] != NULL; i++)
        my_printf("%s\n", board[i]);
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
