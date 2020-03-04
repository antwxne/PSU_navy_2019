/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** com_game
*/

#include <stdbool.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "navy.h"
#include "my.h"

static const char let[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
static const int cols[] = {2, 4, 6, 8, 10, 12, 14, 16};

static void handler(int sig, siginfo_t *info, void *ncontext)
{
    if (sig == SIGUSR1)
        recep_sig = 1;
    if (sig == SIGUSR2)
        recep_sig = -1;
    usleep(10000);
    kill(info->si_pid, SIGUSR1);
}

static void display_hit(int *pos, int hit)
{
    my_printf("%c%c:", let[pos[0]-1], pos[1] + '0');
    if (hit == 1)
        my_putstr("  hit\n");
    else
        my_putstr("  missed\n");
}

int check_hit(char **board, int *pos)
{
    if (board[pos[0]-1][cols[pos[0]-1]] >= '2' &&
        board[pos[0]-1][cols[pos[0]-1]] <= '5')
        return (1);
    else
        return (-1);
    return (0);
}

int send_all(int *pos, int pid)
{
    struct sigaction act = {0};

    my_send_sig(pos[0], pid);
    usleep(20000);
    my_send_sig(pos[1], pid);
    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = &handler;
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    pause();
    if (recep_sig == 1)
        display_hit(pos, 1);
    else
        display_hit(pos, 0);
    return (recep_sig);
}

char **recep_all(char **board, int *pos, int other_pid)
{
    pos[0] = get_signal();
    pos[1] = get_signal();
    usleep(10000);
    if (check_hit(board, pos) == 1) {
        display_hit(pos, 1);
        kill(other_pid, SIGUSR1);
    }
    if (check_hit(board, pos) == -1) {
        display_hit(pos, 0);
        kill(other_pid, SIGUSR2);
    }
    pause();
    board = update_my_board(board, pos);
    return (board);
}