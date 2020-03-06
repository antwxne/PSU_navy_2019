/*
** EPITECH PROJECT, 2020
** replace
** File description:
** replace
*/

#include <stdio.h>
#include <stdlib.h>

static int hori(char *buffer, int i)
{
    int x = 0;

    if (buffer[i] == 'A')
        x = 2;
    if (buffer[i] == 'B')
        x = 4;
    if (buffer[i] == 'C')
        x = 6;
    if (buffer[i] == 'D')
        x = 8;
    if (buffer[i] == 'E')
        x = 10;
    if (buffer[i] == 'F')
        x = 12;
    if (buffer[i] == 'G')
        x = 14;
    if (buffer[i] == 'H')
        x = 16;
    return x;
}

static int ifletter(char *buffer, int k)
{
    int bis = 0;
    int x = 0;

    x = hori(buffer, (k+2));
    bis = hori(buffer, (k + 5));

    if (x == bis)
        return 1;
    else
        return 0;
}

static int verti(char *buffer, int i)
{
    int y = 0;

    y = buffer[i] - '0' + 1;

    return y;
}

char **replace_map(char *buffer, char **boat, int k)
{
    int x = hori(buffer, (k+2));
    int y = verti(buffer, (k+3));
    int letter = ifletter(buffer, k);
    int nature = buffer[k] - '0';

    if (letter == 1)
        for (int k = 0; k < nature; k++, y++) {
            if (boat[y][x] == '.')
                boat[y][x] = nature + '0';
            else
                return NULL;
        }
    else {
        for (int k = 0; k < nature; k++, x += 2) {
            if (boat[y][x] == '.')
                boat[y][x] = nature + '0';
            else
                return NULL;
        }
    }
    return boat;
}