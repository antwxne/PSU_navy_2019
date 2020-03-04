/*
** EPITECH PROJECT, 2020
** navy
** File description:
** set_board
*/

#include <stdlib.h>
#include <unistd.h>
#include "navy.h"
#include "my.h"

static void first_display(char **board, char **enemy)
{
    my_putstr("\nmy positions:\n");
    display_board(board);
    my_putchar('\n');
    my_putstr("enemy’s positions:\n");
    display_board(enemy);
}

static char **waiting_action(char **board, int **pos)
{
    my_putstr("\nwaiting for enemy's attack...\n");
    board = recep_all(board, pos[1], pos[2][0]);
    return (board);
}

static int input(char **rd)
{
    if (cat_input(rd) == -1) {
        free(*rd);
        return eof;
    }
    while (valid(*rd) == -1) {
        free(*rd);
        cat_input(rd);
        if (*rd == NULL)
            return eof;
        }
    return (1);
}

int loop_p1(char **board, char **enemy, int **pos, int pid)
{
    char *rd = NULL;
    int ret = 0;

    pos[2][0] = pid;
    while (1) {
        first_display(board, enemy);
        if (input(&rd) == eof)
            return (eof);
        ret = second_loop(pos, rd, &board, &enemy);
        free(rd);
        if (ret != 0)
            return (ret);
        waiting_action(board, pos);
    }
    return (0);
}

int loop_p2(char **board, char **enemy, int **pos, int pid)
{
    char *rd = NULL;
    int ret = 0;

    pos[2][0] = pid;
    while (1) {
        first_display(board, enemy);
        waiting_action(board, pos);
        usleep(10000);
        if (input(&rd) == eof)
            return (eof);
        ret = second_loop(pos, rd, &board, &enemy);
        free(rd);
        if (ret != 0)
            return (ret);
    }
    return (0);
}
