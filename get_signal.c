/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** signal
*/

#include "navy.h"
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

static const char letter[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

void recep_signal(int sig)
{
    const struct sigaction *act;
    struct sigaction *oldact;
    sigaction(sig, act, oldact);
    printf("signal = %d\n", sig);
}

void get_mypid(void)
{
    printf("pid = %d\n", getpid());
    while (1)
        signal(SIGUSR1, recep_signal);
}

int main(int ac, char **av)
{
        get_mypid();
        return (0);
}
