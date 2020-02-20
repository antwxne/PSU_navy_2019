/*
** EPITECH PROJECT, 2020
** navy_test
** File description:
** main
*/

#include "navy.h"
#include <stdlib.h>

int main(int ac, char **av)
{
    int k = 0;
    char *buffer = read_posi(av[1]);
    char **board = create_board();

    if (error(ac, av, buffer) == 84)
        return 84;
    for ( ;k <= 24; k += 8) {
        board = replace_map(buffer, board, (k));
        if (board == NULL)
            return 84;
    }
    display_board(board);
    my_free_arr(board, 2);
    return 0;
}
