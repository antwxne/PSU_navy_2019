/*
** EPITECH PROJECT, 2020
** navy_test
** File description:
** navy
*/

#ifndef NAVY_H_
#define NAVY_H_

#include "my.h"
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

char **create_board(void);
void display_board(char **board);

#endif /* !NAVY_H_ */
