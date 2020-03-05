/*
** EPITECH PROJECT, 2020
** navy_test
** File description:
** main
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "navy.h"
#include "my.h"

int main(int ac, char **av)
{
    char *buffer = read_posi(av[ac - 1]);
    int end = 0;
    sfSound **sound = my_sound();

    recep_sig = 0;
    if (error(ac, av, buffer) == 84 || sound == NULL) {
        free(buffer);
        return 84;
    }
    if (ac == 2)
        end = game_loop(buffer, sound);
    if (ac == 3)
        end = game_loop_2(buffer, my_getnbr(av[1]), sound);
    if (end == -1)
        return (0);
    end == 0 ? my_putstr("\nI won\n") : my_putstr("\nEnemy won\n");
    return (end == 0 ? 0 : 1);
}
