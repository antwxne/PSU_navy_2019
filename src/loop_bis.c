/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** loop_bis
*/

#include <stdbool.h>
#include <stdlib.h>
#include "navy.h"
#include "my.h"

static void hit(char **board, char **enemy, char *pos, bool check)
{
    printf("hit my board\n");
    enemy = update_enemy_board(board, check, pos);
    display_board(board);
    my_putchar('\n');
    display_board(enemy);
}

static int loose(char **boat, char *rd)
{
    int cols = take_colone(rd);
    int rows = take_line(rd);
    static int lose = 0;

    if (boat[rows][cols] != '.')
        lose += 1;
    if (lose == 14)
        return -1;
    return 0;
}

int second_loop(int **pos, char *rd, char ***board, char ***enemy)
{
    bool fire;

    pos[0] = transform_input(rd);
    fire = send_all(pos[0], pos[2][0]);
    enemy[0] = update_enemy_board(enemy[0], fire, rd);
    if (loose(enemy[0], rd) == -1)
        return (enemy);
    if (loose(board[0], rd) == -1)
        return (you);
    return (0);
}
