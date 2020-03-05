/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** connect
*/

#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "navy.h"
#include "my.h"

static void handler_connect(int sig, siginfo_t *info)
{
    if (sig == SIGUSR1) {
        recep_sig = info->si_pid;
        kill(info->si_pid, SIGUSR2);
    }
}

int init_connection(int pid)
{
    struct sigaction act = {0};

    my_printf("my_pid:  %d\n", getpid());
    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = &handler_connect;
    sigaction(SIGUSR2, &act, NULL);
    kill(pid, SIGUSR1);
    pause();
    my_putstr("successfully connected\n");
    return (pid);
}

int wait_connection(void)
{
    struct sigaction act = {0};

    my_printf("my_pid:  %d\nwaiting for enemy connection...\n", getpid());
    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = &handler_connect;
    sigaction(SIGUSR1, &act, NULL);
    pause();
    my_putstr("\nenemy connected\n");
    return (recep_sig);
}