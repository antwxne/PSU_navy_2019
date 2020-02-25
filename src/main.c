/*
** EPITECH PROJECT, 2020
** navy_test
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "navy.h"

int main(int ac, char **av)
{
    int k = 0;
    char *buffer = read_posi(av[1]);
    char **board = create_board();
    char **enemy = create_board();
    char *rd = NULL;
    int a = 1;
    char **sec = NULL;
    int *pos = malloc(sizeof(int)*2);

    if (error(ac, av, buffer) == 84)
        return 84;
     for ( ;k <= 24; k += 8) {
         board = replace_map(buffer, board, (k));
        if (board == NULL)
            return 84;
     }
     while (1){
     display_board(board);
     //   my_putchar('\n');
     enemy = final_map(board);
     display_board(enemy);
     //my_putchar('\n');
     rd = cat_input();
     if (rd == NULL)
         return 0;
     while (valid(rd) == -1) {
         rd = cat_input();
         if (rd == NULL)
             return 0;    
     }
     pos[0] = take_line(rd);
     pos[1] = take_colone(rd);
     enemy = toucher(board, pos);
     printf("hit ===== %d\n", enemy[pos[0]][pos[1]] == 'x' ? true : false);
     display_board(board);
     my_putchar('\n');
     display_board(enemy);
     }
     //if (loose(board, rd) == -1)
     //  printf("You_loose\n");}
     my_free_arr(board, 2);
     my_free_arr(enemy, 2);
     return 0;
}
