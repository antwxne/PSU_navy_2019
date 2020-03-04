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

static const char let[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
static const int cols[] = {2, 4, 6, 8, 10, 12, 14, 16};

char **update_my_board(char **boat, int *pos)
{
    int y = pos[1] + 2;
    int x = cols[pos[0]-1];

    if (boat[y][x] != '.' && boat[y][x] != 'o')
        boat[y][x] = 'x';
    else if (boat[y][x] == '.' || boat[y][x] == 'o')
        boat[y][x] = 'o';
    return (boat);
}

char **update_enemy_board(char **enemy, bool hit, int *pos)
{
    int i = 0;

    for (; i <= 7; i++)
        if (let[i] == pos[0])
            break;
    if (hit == true)
        enemy[pos[1]+1][cols[pos[0]-1]] = 'x';
    else
        enemy[pos[1]+1][cols[pos[0]-1]] = 'o';
    return (enemy);
}