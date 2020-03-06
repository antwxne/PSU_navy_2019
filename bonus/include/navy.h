/*
** EPITECH PROJECT, 2020
** navy_test
** File description:
** navy
*/

#ifndef NAVY_H_
#define NAVY_H_

#include <SFML/Audio.h>

int recep_sig;

typedef struct my_sounds {
    sfSound **sound;
    sfSoundBuffer **buff;
} sounds_t;

typedef enum sounds {
    boom,
    plouf,
    pirate,
} sounds_e;

typedef enum player {
    you,
    other
} player_e;

void display_board(char **board);
char **create_board(void);
int valid(char *boat);
int take_colone(char *boat);
int take_line(char *boat);
int send_all(int *pos, int pid);
char **recep_all(char **board, int *pos, int other_pid, sounds_t sound);
int init_connection(int pid);
int wait_connection(void);
int error(int ac, char *buffer);
int game_loop_2(char *map, int pid, sounds_t sound);
int game_loop(char *map, sounds_t sound);
int *transform_input(char *input, int *result);
int cat_input(char **input);
int second_loop(int **pos, char *rd, char ***enemy);
int loop_p1(char **board, char **enemy, int **pos, sounds_t sound);
int loop_p2(char **board, char **enemy, int **pos, sounds_t sound);
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
int loose(char **boat);
int my_sound(sounds_t *element);
void destroy_sound(sounds_t *sound);
char **set_board(char **board, char *map);  

#endif /* !NAVY_H_ */
