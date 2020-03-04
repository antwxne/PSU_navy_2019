/*
** EPITECH PROJECT, 2020
** check
** File description:
** check
*/

#include "navy.h"
#include "my.h"

int valid(char *boat)
{
    if ((boat[0] >= 'A' && boat[0] <= 'H')
        && (boat[1] >= '1' && boat[1] <= '8'))
                return 0;
    else {
        my_putstr("wrong position\n");
        return -1;
    }
}

int take_colone(char *boat)
{
    int i = 0;

    if (boat[0] == 'A')
        i = 2;
    if (boat[0] == 'B')
        i = 4;
    if (boat[0] == 'C')
        i = 6;
    if (boat[0] == 'D')
        i = 8;
    if (boat[0] == 'E')
        i = 10;
    if (boat[0] == 'F')
        i = 12;
    if (boat[0] == 'G')
        i = 14;
    if (boat[0] == 'H')
        i = 16;
    return i;
}

int take_line(char *boat)
{
    int i = 0;

    if (boat[1] == '1')
        i = 2;
    if (boat[1] == '2')
        i = 3;
    if (boat[1] == '3')
        i = 4;
    if (boat[1] == '4')
        i = 5;
    if (boat[1] == '5')
        i = 6;
    if (boat[1] == '6')
        i = 7;
    if (boat[1] == '7')
        i = 8;
    if (boat[1] == '8')
        i = 9;
    return i;
}
