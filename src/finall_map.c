/*
** EPITECH PROJECT, 2020
** final
** File description:
** map
*/

#include "navy.h"
#include <stdbool.h>

char **final_map(char **enemy, int y, int x, int hit)
{
    if (hit == true)
        enemy[y][x] = 'x';
    if (hit == false)
        enemy[y][x] = 'o';
    return (enemy);
}
