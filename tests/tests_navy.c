/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** tests_navy
*/

#include <criterion/criterion.h>
#include "navy.h"

Test (loose, test_true)
{
    char *board[] = {" |A B C D E F G H",
                    "-+---------------",
                    "1|. . x . . . . .",
                    "2|. . x . . . . .",
                    "3|. . . . . . . .",
                    "4|. . . x x x . .",
                    "5|. x . . . . . .",
                    "6|. x . . . . . .",
                    "7|. x . x x x x x",
                    "8|. x . . . . . .",
                    NULL};
    int got = loose(board);
    cr_assert_eq(got, -1);
}