/*
** EPITECH PROJECT, 2020
** navy
** File description:
** set_board
*/

#include <stdlib.h>
#include "navy.h"
#include "my.h"

static void first_display(char **board, char **enemy)
{
    my_putstr("my positions:\n");
    display_board(board);
    my_putchar('\n');
    my_putstr("enemy’s positions:\n");
    display_board(enemy);
}

char **waiting_action(char **board, int **pos)
{
    my_putstr("\nwaiting for enemy's attack...\n");
    board = recep_all(board, pos[1], pos[2][0]);
    return (board);
}

int loop_p1(char **board, char **enemy, int **pos, int pid)
{
    char *rd = NULL;
    int ret = 0;

    pos[2][0] = pid;
    first_display(board, enemy);
    while (1) {
        rd = cat_input();
        if (rd == NULL)
            return eof;
        while (valid(rd) == -1) {
            rd = cat_input();
            if (rd == NULL)
                return eof;
        }
        ret = second_loop(pos, rd, &board, &enemy);
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
    first_display(board, enemy);
    while (1) {
        waiting_action(board, pos);
        usleep(1000);
        rd = cat_input();
        if (rd == NULL) {
            return eof;
        }
        while (valid(rd) == -1) {
            rd = cat_input();
            if (rd == NULL)
                return eof;
        }
        ret = second_loop(pos, rd, &board, &enemy);
        if (ret != 0)
            return (ret);
    }
    return (0);
}
