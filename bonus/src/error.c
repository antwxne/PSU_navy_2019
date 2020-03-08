/*
** EPITECH PROJECT, 2020
** error
** File description:
** error
*/

#include <stddef.h>
#include "navy.h"
#include "my.h"

int error(int ac, char *buffer)
{
    char **board;

    if (ac < 2 || ac > 3)
        return (84);
    if (buffer == NULL ||
    first_verification(buffer) == -1 || second_verification(buffer) == -1 ||
    three_verification(buffer) == -1 || four_verification(buffer) == -1)
        return (84);
    board = (set_board(create_board(), buffer));
    if (board == NULL)
        return (84);
    my_free_arr(board, 2);
    return (0);
}
