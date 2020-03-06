/*
** EPITECH PROJECT, 2020
** navy_test
** File description:
** main
*/

#include <stdlib.h>
#include "navy.h"
#include "my.h"

int main(int ac, char **av)
{
    char *buffer = read_posi(av[ac - 1]);
    int end = 0;

    recep_sig = 0;
    if (error(ac, buffer) == 84) {
        free(buffer);
        return 84;
    }
    if (ac == 2)
        end = game_loop(buffer);
    if (ac == 3)
        end = game_loop_2(buffer, my_getnbr(av[1]));
    if (end == -1)
        return (0);
    end == 0 ? my_putstr("\nI won\n") : my_putstr("\nEnemy won\n");
    return (end == 0 ? 0 : 1);
}
