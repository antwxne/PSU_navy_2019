/*
** EPITECH PROJECT, 2020
** navy_test
** File description:
** main
*/

#include "navy.h"
#include "my.h"

int main(int ac, char **av)
{
    char *buffer = read_posi(av[ac - 1]);

    recep_sig = 0;
    if (error(ac, av, buffer) == 84)
        return 84;
    if (ac == 2)
        return (game_loop(buffer));
    if (ac == 3)
        return (game_loop_2(buffer, my_getnbr(av[1])));
    return 0;
}
