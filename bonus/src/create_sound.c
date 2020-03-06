/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** create_sound
*/

#include <stdlib.h>
#include "navy.h"

static const char *filepath[] = {"resources/boom.ogg",
                                "resources/plouf.ogg",
                                "resources/pirate.ogg",
                                NULL};

void destroy_sound(sounds_t *sound)
{
    for (int i = 0; sound->sound[i] != NULL; i++) {
        sfSound_destroy(sound->sound[i]);
        sfSoundBuffer_destroy(sound->buff[i]);
    }
}

int my_sound(sounds_t *element)
{
    sfSound **sound = malloc(sizeof(sfSound *)*4);
    sfSoundBuffer **buff = malloc(sizeof(sfSoundBuffer *)*3);

    if (sound == NULL || buff == NULL)
        return (-1);
    for (int i = 0; filepath[i] != NULL; i++) {
        buff[i] = sfSoundBuffer_createFromFile(filepath[i]);
        if (buff[i] == NULL)
            return (-1);
        sound[i] = sfSound_create();
        sfSound_setBuffer(sound[i], buff[i]);
    }
    sfSound_setLoop(sound[2], sfTrue);
    sfSound_setVolume(sound[2], 50);
    sound[3] = NULL;
    element->sound = sound;
    element->buff = buff;
    return (0);
}