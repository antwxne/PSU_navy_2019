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
    if (ac < 2 && ac > 3)
        return (84);
    if (buffer == NULL)
        return (84);
    if (first_verification(buffer) == -1)
        return (84);
    if (second_verification(buffer) == -1)
        return (84);
    if (three_verification(buffer) == -1)
        return (84);
    if (four_verification(buffer) == -1)
        return (84);
    return (0);
}
