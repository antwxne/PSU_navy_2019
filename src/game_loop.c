/*
** EPITECH PROJECT, 2020
** navy
** File description:
** game_loop
*/

#include <stdlib.h>
#include "navy.h"

static char **set_board(char **board, char *map)
{
    int k = 0;

    for (;k <= 24; k += 8) {
        board = replace_map(map, board, (k));
        if (board == NULL)
            return (NULL);
    }
    return (board);
}

int game_loop_2(char *map, int pid)
{
    char **board = set_board(create_board(), map);
    char **enemy = create_board();
    int *pos = malloc(sizeof(int)*2);
    int return_value = loop(board, enemy, pos, init_connection(pid));

    free(pos);
    my_free_arr(board, 2);
    my_free_arr(enemy, 2);
    return (return_value);
}

int game_loop(char *map)
{
    char **board = set_board(create_board(), map);
    char **enemy = create_board();
    int *pos = malloc(sizeof(int)*2);
    int return_value = loop(board, enemy, pos, wait_connection());

    free(pos);
    my_free_arr(board, 2);
    my_free_arr(enemy, 2);
    return (return_value);
}
