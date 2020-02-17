/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** test_sig
*/

#include "include/navy.h"
#include <stdio.h>

#define INPUT av[1]
#define PID av[2]

static const char letter[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

int send_signal(char *input, pid_t pid)
{
    printf("send pid %d\n", pid);
    int i = 0;
    int sig = 0;
    for (; input[0] != letter[i]; i++);
    sig = 10 * i;
    sig += input[1] + '0';
    sig *= 1000;
    int err = kill(pid, SIGUSR1);
    printf("kill return == %d\n", err);
    perror(err);
    //free(input);
}

int main(int ac, char **av)
{
    printf("my_pid == %d\n", getpid());
    send_signal(INPUT, atoi(PID));
    return (0);
}
