/*
** EPITECH PROJECT, 2020
** navy
** File description:
** set_board
*/

#include "navy.h"

static void first_display(char **board, char **enemy)
{
    my_putstr("my positions:\n");
    display_board(board);
    my_putchar('\n');
    my_putstr("enemy’s positions:\n");
    display_board(enemy);
    my_putchar('\n');
}

static void hit(char **board, char **enemy, int *pos)
{
    enemy = toucher(board, pos);
    display_board(board);
    my_putchar('\n');
    display_board(enemy);
}

static int check_loose(char **board)
{
    int y = 2;

    for (; board[y] != NULL; y++)
        for (int x = 2; board[y][x] != 0; x++)
            if (board[y][x] >= '2' && board[y][x] <= '5')
                return (1);
    return (0);
}

int loop(char **board, char **enemy, int *pos, int pid)
{
    char *rd = NULL;

    first_display(board, enemy);
    while (check_loose(board)) {
        rd = cat_input();
        if (rd == NULL)
            return eof;
        while (valid(rd) == -1) {
            rd = cat_input();
            if (rd == NULL)
                return eof;
        }
        pos[0] = take_line(rd);
        pos[1] = take_colone(rd);
        hit(board, enemy, pos);
    }
    return (0);
}
