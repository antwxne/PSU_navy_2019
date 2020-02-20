/*
** EPITECH PROJECT, 2020
** navy_test
** File description:
** navy
*/

#ifndef NAVY_H_
#define NAVY_H_

#include "my.h"

char **create_board(void);
void display_board(char **board);
char *read_posi(char *filepath);
int first_verification(char *buffer);
int second_verification(char *buffer);
int three_verification(char *buffer);
int fore_verification(char *buffer);
char **replace_map(char *buffer, char **boat, int k);
#endif /* !NAVY_H_ */
