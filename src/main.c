/*
** EPITECH PROJECT, 2020
** navy_test
** File description:
** main
*/

#include "navy.h"
#include <stdlib.h>

int main(void)
{
    char **board = create_board();
    display_board(board);
    my_free_arr(board, 2);
    return (0);
}
