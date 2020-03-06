/*
** EPITECH PROJECT, 2020
** navy
** File description:
** game_loop
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "navy.h"
#include "my.h"

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

static void free_int(int **arr)
{
    free(arr[0]);
    free(arr[1]);
    free(arr[2]);
    free(arr);
}

static void destroy(char *map, int **pos, char **board, char **enemy)
{
    free_int(pos);
    free(map);
    my_free_arr(board, 2);
    my_free_arr(enemy, 2);
}

int game_loop_2(char *map, int pid, sounds_t sound)
{
    char **board = set_board(create_board(), map);
    char **enemy = create_board();
    int **pos = malloc(sizeof(int *)*3);
    int return_value;

    if (pos == NULL)
        return (84);
    for (int i = 0; i <= 2; i++) {
        pos[i] = malloc(sizeof(int)*2);
        if (pos[i] == NULL)
            return (84);
    }
    pos[2][0] = init_connection(pid);
    return_value = loop_p2(board, enemy, pos, sound);
    destroy(map, pos, board, enemy);
    destroy_sound(&sound);
    return (return_value);
}

int game_loop(char *map, sounds_t sound)
{
    char **board = set_board(create_board(), map);
    char **enemy = create_board();
    int **pos = malloc(sizeof(int *)*3);
    int return_value;

    if (pos == NULL)
        return (84);
    for (int i = 0; i <= 2; i++) {
        pos[i] = malloc(sizeof(int)*2);
        if (pos[i] == NULL)
            return (84);
    }
    pos[2][0] = wait_connection();
    return_value = loop_p1(board, enemy, pos, sound);
    destroy(map, pos, board, enemy);
    destroy_sound(&sound);
    return (return_value);
}
