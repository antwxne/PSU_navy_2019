/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** my_strcat
*/

#include <unistd.h>
#include <stdlib.h>

char *my_strcat(char *str1, char const *str2)
{
    int count_str1 = 0;
    int count_str2 = 0;
    int count_dest = 0;
    char *dest;

    for (; str1[count_str1] != 0; count_str1++);
    for (; str2[count_str2] != 0; count_str2++);
    dest = malloc(sizeof(char)*(count_str1+count_str2+2));
    if (dest == NULL)
        return (0);
    for (int i = 0; i < count_str1; i++, count_dest++)
        dest[count_dest] = str1[i];
    for (int i = 0; i < count_str2; i++, count_dest++)
        dest[count_dest] = str2[i];
    dest[count_str1+count_str2] = 0;
    return (dest);
}