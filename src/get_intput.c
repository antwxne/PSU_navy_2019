/*
** EPITECH PROJECT, 2020
** tkt
** File description:
** tkt
*/

#include "navy.h"

char *cat_input(void)
{
    char *input;
    int fd = 0;
    
    input = get_next_line(fd);
    return input;
}
