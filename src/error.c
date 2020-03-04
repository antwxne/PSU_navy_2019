/*
** EPITECH PROJECT, 2020
** error
** File description:
** error
*/

#include <stddef.h>
#include "navy.h"

int error(int ac, char **av, char *buffer)
{
    int i = 0;

    if (ac == 2)
        i = 1;
    else if (ac == 3)
        i = 2;
    else
        return 84;
    if (read_posi(av[i]) == NULL)
        return 84;
    buffer = read_posi(av[i]);
    if (first_verification(buffer) == -1)
        return 84;
    if (second_verification(buffer) == -1)
        return 84;
    if (three_verification(buffer) == -1)
        return 84;
    if (four_verification(buffer) == -1)
        return 84;
    return 0;
}
