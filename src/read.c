/*
** EPITECH PROJECT, 2020
** read
** File description:
** read
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

char *read_posi(char *filepath)
{
    int fd = 0;
    char *buffer;
    int size;

    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return NULL;
    buffer = malloc(sizeof(char) * 45);
    size =  read(fd, buffer, 45);
    buffer[31] = 0;
    close(fd);
    if (size > 31)
        return NULL;
    return buffer;
}

int first_verification(char *buffer)
{
    if ((buffer[0] >= '2' && buffer[0] <= '5') &&
        (buffer[8] >= '2' && buffer[8] <= '5') &&
        (buffer[16] >= '2' && buffer[16] <= '5') &&
        (buffer[24] >= '2' && buffer[24] <= '5'))
        return 0;
    else
        return -1;
}

int second_verification(char *buffer)
{
    int two = 0;
    int three = 0;
    int four = 0;
    int five = 0;

    for (int i = 0; i <= 24; i += 8) {
        if (buffer[i] == '2')
            two  += 1;
        if (buffer[i] == '3')
            three += 1;
        if (buffer[i] == '4')
            four += 1;
        if (buffer[i] == '5')
            five += 1;
    }
    if (two == 1 && three == 1 && four == 1 && five == 1)
        return 0;
    else
        return -1;
}

int three_verification(char *buffer)
{

    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] != ':' && (buffer[i] < 'A' || buffer[i] > 'H') &&
            (buffer[i] < '1' || buffer[i] > '8') && buffer[i] != '\n')
            return -1;

    if (buffer[1] == ':' && buffer[4] == ':' &&
        buffer[9] == ':' && buffer[12] == ':' &&
        buffer[17] == ':' && buffer[20] == ':' &&
        buffer[25] == ':' && buffer[28] == ':')
        return 0;
    else
        return -1;
}

int four_verification(char *buffer)
{
    int i = 2;
    int res = 0;

    for (; i <= 26; i += 8) {
        if (buffer[i] == buffer[i + 3]) {
            res = buffer[i + 4] - buffer[i + 1];
            if (!((res + 49) == buffer[i - 2]))
                return -1;
        }
        else if (buffer[i + 1] == buffer[i + 4]) {
            res = buffer[i + 3] - buffer[i];
            if (!((res + 49) == buffer[i - 2]))
                return -1;
        }
        else
            return -1;
    }
    return 0;
}
