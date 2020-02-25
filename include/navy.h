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
char *read_posi(char *filepath);
int first_verification(char *buffer);
int second_verification(char *buffer);
int three_verification(char *buffer);
int fore_verification(char *buffer);
char **replace_map(char *buffer, char **boat, int k);
int take_colone(char *boat);
int check_line(char *boat);
int valid(char *boat);
int error(int ac, char **av, char *buffer);
char **toucher(char **boat, int *pos);
int loose(char **boat, char *rd);
char *cat_input(void);
char *get_next_line(int fd);

#endif /* !NAVY_H_ */
