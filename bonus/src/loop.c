/*
** EPITECH PROJECT, 2020
** navy
** File description:
** set_board
*/

#include <SFML/Audio.h>
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

static char **waiting_action(char **board, int **pos, sfSound **sound)
{
    my_putstr("\nwaiting for enemy's attack...\n");
    board = recep_all(board, pos[1], pos[2][0], sound);
    return (board);
}

static int input(char **rd)
{
    if (cat_input(rd) == -1) {
        free(*rd);
        return 0;
    }
    while (valid(*rd) == -1) {
        free(*rd);
        cat_input(rd);
        if (*rd == NULL)
            return 0;
        }
    return (1);
}

int loop_p1(char **board, char **enemy, int **pos, sfSound **sound)
{
    char *rd = NULL;

    while (1) {
        first_display(board, enemy);
        if (input(&rd) == 0)
            return (-1);
        if (second_loop(pos, rd, &enemy) == -1) {
            first_display(board, enemy);
            return (you);
        }
        board = waiting_action(board, pos, sound);
        if (loose(board) == -1) {
            first_display(board, enemy);
            return (other);
        }
    }
    return (0);
}

int loop_p2(char **board, char **enemy, int **pos, sfSound **sound)
{
    char *rd = NULL;

    while (1) {
        first_display(board, enemy);
        board = waiting_action(board, pos, sound);
        if (loose(board) == -1) {
            first_display(board, enemy);
            return (other);
        }
        usleep(10000);
        if (input(&rd) == 0)
            return (-1);
        if (second_loop(pos, rd, &enemy) == -1) {
            first_display(board, enemy);
            return (you);
        }
    }
    return (0);
}
