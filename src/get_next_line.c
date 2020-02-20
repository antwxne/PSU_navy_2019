/*
** EPITECH PROJECT, 2019
** get
** File description:
** next line
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char *str_cat(char *buffer, char *line)
{
    int size = 0;
    int j = 0;
    char *temp;
    int index = 0;

    for ( ; buffer[size] != '\0'; size++);
    for ( ; line[j] != '\0'; j++, size++);
    temp = malloc(sizeof(char) * (size + 1));
    for ( ; line && line[index] != '\0'; index++) {
        temp[index] = line[index];
    }
    for (int i = 0; buffer[i] != '\n' && buffer[i] != '\0'; index++, i++) {
        temp[index] = buffer[i];
    }

    return temp;
}

int check_n(char *buffer)
{
    for (int i = 0; buffer[i] != 0; i++)
        if (buffer[i] == '\n')
            return 0;
    return 1;
}

char *get_next_line(int fd)
{
    static char buffer[700 + 1] ;
    char *line = "\0";
    int rd = 0;
    int o = 1;

    while (o) {
        rd = read(fd, buffer, 700);
        buffer[rd + 1] = '\0';
        line = str_cat(buffer, line);
        o = check_n(buffer);
        if (rd  <= 0)
            return NULL;
        if (fd == -1)
            return NULL;
        if (buffer == NULL)
            return NULL;
    }
    return line;
}
