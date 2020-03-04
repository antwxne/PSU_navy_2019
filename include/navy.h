/*
** EPITECH PROJECT, 2020
** navy_test
** File description:
** navy
*/

#ifndef NAVY_H_
#define NAVY_H_

#include <stdbool.h>

int recep_sig;

typedef enum player {
    eof,
    you,
    other
} player_e;

void display_board(char **board);
char **create_board(void);
int valid(char *boat);
int take_colone(char *boat);
int take_line(char *boat);
int send_all(int *pos, int pid);
char **recep_all(char **board, int *pos, int other_pid);
int init_connection(int pid);
int wait_connection(void);
int error(int ac, char **av, char *buffer);
int game_loop_2(char *map, int pid);
int game_loop(char *map);
int *transform_input(char *input);
int cat_input(char **input);
int second_loop(int **pos, char *rd, char ***board, char ***enemy);
int loop_p1(char **board, char **enemy, int **pos, int pid);
int loop_p2(char **board, char **enemy, int **pos, int pid);
char *read_posi(char *filepath);
int first_verification(char *buffer);
int second_verification(char *buffer);
int three_verification(char *buffer);
int four_verification(char *buffer);
char **replace_map(char *buffer, char **boat, int k);
int get_signal(void);
char **update_my_board(char **boat, int *pos);
char **update_enemy_board(char **enemy, int hit, int *pos);
void my_send_sig(int data, int pid);
int check_hit(char **board, int *pos);

#endif /* !NAVY_H_ */
