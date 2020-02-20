/*
** EPITECH PROJECT, 2020
** navy
** File description:
** send data by sig
*/

#include <sys/types.h>
#include <signal.h>
#include <stddef.h>
#include <stdio.h>

int my_send_sig(int data, int pid)
{
    for (int i = 0; i <= 3;) {
        if ((data >> i) % 2 == 1)
            kill(pid, SIGUSR1);
        if ((data >> i) % 2 == 0)
            kill(pid, SIGUSR2);
        sleep(1);
        i++;
    }
}
