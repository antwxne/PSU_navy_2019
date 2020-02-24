/*
** EPITECH PROJECT, 2020
** tkt
** File description:
** tkt
*/

#include "navy.h"
#include <stdlib.h>
#include <stdio.h>

static const char let[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

int *transform_input(char *input)
{
    int i = 0;
    int *result = malloc(sizeof(int)*2);

    if (result == NULL)
        return (NULL);
    if (input[0] >= 'A' && input[0] <= 'H') {
        for (; let[i] != input[0]; i++);
        result[0] = (i+1);
        result[1] = input[1] - '0';
    } else {
        for (; let[i] != input[1]; i++);
        result[0] = (i+1);
        result[1] = input[0] - '0';
    }
    return (result);
}

char *cat_input(void)
{
    char *input = NULL;
    size_t getnext = 0;

    my_putstr("attack: ");
    if (getline(&input, &getnext, stdin) == -1)
        return  NULL;
    return input;
}
