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
