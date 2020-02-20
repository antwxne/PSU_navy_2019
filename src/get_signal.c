/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** signal
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int recep_sig = 0;

void handler(int sig, siginfo_t *info, void *ucontext)
{
    if (sig == SIGUSR1)
        recep_sig = 1;
    if (sig == SIGUSR2)
        recep_sig = 0;
    kill(info->si_pid, SIGUSR1);
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

void get_mypid(void)
{
    struct sigaction act;
    int pid = getpid();
    int i = 0;
    char *bin = malloc(sizeof(char)*5);
    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = &handler;
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    my_printf("wait pid = %d\n", pid);
    while (i < 4) {
        pause();
        bin[i] = recep_sig + '0';
        i++;
    }
    bin[4] = 0;
    bin = clean_bin(bin);
    my_printf("binary = %d\n", my_btoi(my_revstr(bin)));
}
