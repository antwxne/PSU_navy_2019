/*
** EPITECH PROJECT, 2020
** toucher
** File description:
** tocher
*/

#include "navy.h"
#include <stdlib.h>
#include <stdio.h>

char **toucher(char **boat, char *rd)
{
    int line = check_line(rd);
    int colo = take_colone(rd);

    if (boat[colo][line] != '.')
        boat[colo][line] = 'x';
    else if (boat[colo][line] == '.')
        boat[colo][line] = 'o';
    return boat;
}

int loose(char **boat, char *rd)
{
    int line = check_line(rd);
    int colo = take_colone(rd);
    static int lose = 0;

    if (boat[colo][line] != '.')
        lose += 1;
    if (lose == 14)
        return -1;
    return 0;
}
