/*
** EPITECH PROJECT, 2020
** toucher
** File description:
** tocher
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "navy.h"

static const int cols[] = {2, 4, 6, 8, 10, 12, 14, 16};

int check_hit(char **board, int *pos)
{
    if (board[pos[1]+1][cols[pos[0]-1]] >= '2' &&
        board[pos[1]+1][cols[pos[0]-1]] <= '5')
        return (1);
    else
        return (-1);
    return (0);
}

char **update_my_board(char **boat, int *pos)
{
    int y = pos[1] + 1;
    int x = cols[pos[0]-1];

    if (boat[y][x] != '.' && boat[y][x] != 'o')
        boat[y][x] = 'x';
    else if (boat[y][x] == '.' || boat[y][x] == 'o')
        boat[y][x] = 'o';
    return (boat);
}

char **update_enemy_board(char **enemy, int hit, int *pos)
{
    if (hit == 1)
        enemy[pos[1]+1][cols[pos[0]-1]] = 'x';
    else
        enemy[pos[1]+1][cols[pos[0]-1]] = 'o';
    return (enemy);
}