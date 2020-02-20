/*
** EPITECH PROJECT, 2020
** lib
** File description:
** clean binary
*/

#include <stdio.h>

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i] != 0; i++);
    return (i);
}

char *clean_bin(char *bin)
{
    int len = my_strlen(bin);

    for (; len >= 0; len--) {
        if (bin[len] == '0' && bin[len - 1] == '1') {
            bin[len] = 0;
            return (bin);
        }
    }
    return (bin);
}

int main(int ac, char **av)
{
    char *bin;

    if (ac == 2) {
        bin = av[1];
        bin = clean_bin(bin);
        printf("binary = %s\n", bin);
    }
    return (0);
}
