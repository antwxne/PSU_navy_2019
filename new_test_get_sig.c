/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** new_test_get_sig
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

void signal_handler(int signo, siginfo_t *sig_info, ucontext_t *nul)
{
    printf("pid emeteur == %d\n", sig_info->si_pid);
    printf("Received: signal %d\n", signo);
}

int main(int argc, char**argv)
{
    if (argc != 2) {
        fprintf(stderr, "usage: %s signo\n", argv[0]);
        return EXIT_FAILURE;
    }
    int signo = atoi(argv[1]);
    struct sigaction *s;
    /* s->sa_handler = signal_handler; */
    s->sa_flags = SA_SIGINFO;
    s->sa_sigaction = signal_handler;
    printf("Installing signal handler for signal %d\n", signo);
    int retval = sigaction(signo, s, NULL);
    if (retval<0) {
        perror("sigaction failed");
        abort();
    }
    while (1) {
        printf("[%d] Sleeping...\n", getpid());
        sleep(1);
    }
    return EXIT_SUCCESS;
}
