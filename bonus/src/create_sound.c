/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** create_sound
*/

#include <SFML/Audio.h>

static const char *filepath[] = {"resources/boom.ogg",
                                "resources/plouf.ogg"};

void destroy_sound(sfSound **sound)
{
    for (int i = 0; sound[i] != NULL; i++)
        sfSound_destroy(sound[i]);
}

sfSound **my_sound(void)
{
    sfSound **sound = malloc(sizeof(sfSound *)*3);
    sfSoundBuffer *boom = sfSoundBuffer_createFromFile(filepath[0]);
    sfSoundBuffer *plouf = sfSoundBuffer_createFromFile(filepath[1]);
    if (sound == NULL || boom == NULL || plouf == NULL)
        return (NULL);
    sound[0] = sfSound_create();
    sound[1] = sfSound_create();
    sfSound_setBuffer(sound[0], boom);
    sfSound_setBuffer(sound[1], plouf);
    sound[2] = NULL;
    return (sound);
}