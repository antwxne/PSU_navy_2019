/*
** EPITECH PROJECT, 2020
** toucher
** File description:
** tocher
*/

#include "navy.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

char **toucher(char **boat, int *pos)
{
    if (boat[pos[0]][pos[1]] != '.')
        boat[pos[0]][pos[1]]= 'x';
    else if (boat[pos[0]][pos[1]] == '.')
        boat[pos[0]][pos[1]] = 'o';
    return (boat);
}

int check_hit(char **boat, int *pos)
{
    return (boat[pos[0]][pos[1]] == 'x' ? true : false);
}

int loose(char **boat, char *rd)
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
