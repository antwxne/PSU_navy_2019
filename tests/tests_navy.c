/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** tests_navy
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "navy.h"
#include "my.h"

static void redirect_all(void)
{
    cr_redirect_stderr();
    cr_redirect_stdout();
}

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

Test (loose, test_false)
{
    char *board[] = {" |A B C D E F G H",
                    "-+---------------",
                    "1|. . x . . . . .",
                    "2|. . x . . . . .",
                    "3|. . . . . . . .",
                    "4|. . . x x x . .",
                    "5|. x . . . . . .",
                    "6|. x . . . . . .",
                    "7|. x . x x x x 5",
                    "8|. x . . . . . .",
                    NULL};
    int got = loose(board);
    cr_assert_eq(got, 0);
}

Test (create_board, tests)
{
    char **got = create_board();
    char *expected[] = {" |A B C D E F G H",
                        "-+---------------",
                        "1|. . . . . . . .",
                        "2|. . . . . . . .",
                        "3|. . . . . . . .",
                        "4|. . . . . . . .",
                        "5|. . . . . . . .",
                        "6|. . . . . . . .",
                        "7|. . . . . . . .",
                        "8|. . . . . . . .",
                        NULL};
    for (int i = 0; got[i] != NULL; i++)
        cr_assert_str_eq(got[i], expected[i]);
    cr_assert_null(got[10]);
    my_free_arr(got, 2);
}

Test (take_colone, test_A)
{
    int got = take_colone("A1");
    int expected = 2;

    cr_assert_eq(got, expected);
}

Test (take_colone, test_B)
{
    int got = take_colone("B1");
    int expected = 4;

    cr_assert_eq(got, expected);
}

Test (take_colone, test_C)
{
    int got = take_colone("C1");
    int expected = 6;

    cr_assert_eq(got, expected);
}

Test (take_colone, test_D)
{
    int got = take_colone("D1");
    int expected = 8;

    cr_assert_eq(got, expected);
}

Test (take_colone, test_E)
{
    int got = take_colone("E1");
    int expected = 10;

    cr_assert_eq(got, expected);
}

Test (take_colone, test_F)
{
    int got = take_colone("F1");
    int expected = 12;

    cr_assert_eq(got, expected);
}

Test (take_colone, test_G)
{
    int got = take_colone("G1");
    int expected = 14;

    cr_assert_eq(got, expected);
}

Test (take_colone, test_H)
{
    int got = take_colone("H1");
    int expected = 16;

    cr_assert_eq(got, expected);
}

Test (take_line, test_1)
{
    int got = take_line("A1");
    int expected = 2;

    cr_assert_eq(got, expected);
}

Test (take_line, test_2)
{
    int got = take_line("A2");
    int expected = 3;

    cr_assert_eq(got, expected);
}

Test (take_line, test_3)
{
    int got = take_line("A3");
    int expected = 4;

    cr_assert_eq(got, expected);
}

Test (take_line, test_4)
{
    int got = take_line("A4");
    int expected = 5;

    cr_assert_eq(got, expected);
}

Test (take_line, test_5)
{
    int got = take_line("A5");
    int expected = 6;

    cr_assert_eq(got, expected);
}

Test (take_line, test_6)
{
    int got = take_line("A6");
    int expected = 7;

    cr_assert_eq(got, expected);
}

Test (take_line, test_7)
{
    int got = take_line("A7");
    int expected = 8;

    cr_assert_eq(got, expected);
}

Test (take_line, test_8)
{
    int got = take_line("A8");
    int expected = 9;

    cr_assert_eq(got, expected);
}

Test (valid, test_true1)
{
    int got = valid("A8");
    int expected = 0;

    cr_assert_eq(got, expected);
}

Test (valid, test_true2)
{
    int got = valid("H1");
    int expected = 0;

    cr_assert_eq(got, expected);
}

Test (valid, test_false1, .init = redirect_all)
{
    int got = valid("A9");
    int expected = -1;

    cr_assert_eq(got, expected);
}

Test (valid, test_false2, .init = redirect_all)
{
    int got = valid("Z2");
    int expected = -1;

    cr_assert_eq(got, expected);
}

Test (transform_input, test1)
{
    int *got = malloc(sizeof(int)*2);
    int expected[] = {1, 2};

    got = transform_input("A2", got);
    cr_assert_eq(got[0], expected[0]);
    cr_assert_eq(got[1], expected[1]);
    free(got);
}

Test (read_posi, test_false_file)
{
    char *got = read_posi("tests/error.txt");

    cr_assert_null(got);
    free(got);
}

Test (read_posi, test_false_file2)
{
    char *got = read_posi("tests/error2.txt");

    cr_assert_null(got);
    free(got);
}

Test (read_posi, test_no_file)
{
    char *got = read_posi("tests/crash");

    cr_assert_null(got);
    free(got);
}

Test (read_posi, true)
{
    char *got = read_posi("tests/true.txt");
    char expected[] = "2:C1:C2\n" \
                        "3:D4:F4\n" \
                        "4:B5:B8\n" \
                        "5:D7:H7";
    cr_assert_str_eq(got, expected);
    free(got);
}

Test (read_posi, true2)
{
    char *got = read_posi("tests/true2.txt");
    char expected[] = "2:C1:C2\n" \
                        "3:D4:F4\n" \
                        "4:B5:B8\n" \
                        "5:D7:H7";
    cr_assert_str_eq(got, expected);
    free(got);
}

Test (first_verification, true)
{
    int got = first_verification("2:C1:C2\n" \
                        "3:D4:F4\n" \
                        "4:B5:B8\n" \
                        "5:D7:H7");
    int expected = 0;

    cr_assert_eq(got, expected);
}

Test (first_verification, false_1)
{
    int got = first_verification("1:C1:C2\n" \
                        "3:D4:F4\n" \
                        "4:B5:B8\n" \
                        "5:D7:H7");
    int expected = -1;

    cr_assert_eq(got, expected);
}

Test (first_verification, false_2)
{
    int got = first_verification("2:C1:C2\n" \
                        "3:D4:F4\n" \
                        "8:B5:B8\n" \
                        "5:D7:H7");
    int expected = -1;

    cr_assert_eq(got, expected);
}

Test (first_verification, false_3)
{
    int got = first_verification("2:C1:C2\n" \
                        "3:D4:F4\n" \
                        "50:B5:B8\n" \
                        "5:D7:H7");
    int expected = -1;

    cr_assert_eq(got, expected);
}

Test (first_verification, false_4)
{
    int got = first_verification("2:C1:C2\n" \
                        "A:D4:F4\n" \
                        "4:B5:B8\n" \
                        "5:D7:H7");
    int expected = -1;

    cr_assert_eq(got, expected);
}

Test (second_verification, true)
{
    int got = second_verification("2:C1:C2\n" \
                        "3:D4:F4\n" \
                        "4:B5:B8\n" \
                        "5:D7:H7");
    int expected = 0;

    cr_assert_eq(got, expected);
}

Test (second_verification, false_1)
{
    int got = second_verification("2:C1:C2\n" \
                        "2:D4:F4\n" \
                        "4:B5:B8\n" \
                        "5:D7:H7");
    int expected = -1;

    cr_assert_eq(got, expected);
}

Test (second_verification, false_2)
{
    int got = second_verification("2:C1:C2\n" \
                        "5:D4:F4\n" \
                        "4:B5:B8\n" \
                        "5:D7:H7");
    int expected = -1;

    cr_assert_eq(got, expected);
}

Test (three_verification, true)
{
    int got = three_verification("2:C1:C2\n" \
                        "3:D4:F4\n" \
                        "4:B5:B8\n" \
                        "5:D7:H7");
    int expected = 0;

    cr_assert_eq(got, expected);
}

Test (three_verification, false_1)
{
    int got = three_verification("2:C1:C2\n" \
                        "3:D4!F4\n" \
                        "4:B5:B8\n" \
                        "5:D7:H7");
    int expected = -1;

    cr_assert_eq(got, expected);
}

Test (three_verification, false_2)
{
    int got = three_verification("2:C1:C2\n" \
                        "3:D4:F4\n" \
                        "4:B5:B8\n" \
                        "5:D7:Z7");
    int expected = -1;

    cr_assert_eq(got, expected);
}

Test (three_verification, false_3)
{
    int got = three_verification("2:C1:C2\n" \
                        "3:D4DF4\n" \
                        "4:B5:B8\n" \
                        "5:D7:H7");
    int expected = -1;

    cr_assert_eq(got, expected);
}

Test (three_verification, false_4)
{
    int got = three_verification("2:C1:C2\n" \
                        "3:D4:F4\n" \
                        "4:B9:B8\n" \
                        "5:D7:H7");
    int expected = -1;

    cr_assert_eq(got, expected);
}

Test (four_verification, true)
{
    int got = four_verification("2:C1:C2\n" \
                        "3:D4:F4\n" \
                        "4:B5:B8\n" \
                        "5:D7:H7");
    int expected = 0;

    cr_assert_eq(got, expected);
}

Test (four_verification, false_1)
{
    int got = four_verification("2:C1:C2\n" \
                        "3:D4:A4\n" \
                        "4:B5:B8\n" \
                        "5:D7:H7");
    int expected = -1;

    cr_assert_eq(got, expected);
}

Test (four_verification, false_3)
{
    int got = four_verification("2:A1:C2\n" \
                        "3:D4:D7\n" \
                        "4:B5:B8\n" \
                        "5:D7:H7");
    int expected = -1;

    cr_assert_eq(got, expected);
}

Test (four_verification, false_4)
{
    int got = four_verification("2:C1:C2\n" \
                        "3:D4:D3\n" \
                        "4:B5:B6\n" \
                        "5:D7:H7");
    int expected = -1;

    cr_assert_eq(got, expected);
}

Test (error, true)
{
    int ac = 2;
    char *av[] = {NULL, "tests/true.txt"};
    char *buffer = read_posi("tests/true.txt");
    int got = error(ac, av, buffer);
    int expected = 0;

    cr_assert_eq(got, expected);
}

Test (error, false1)
{
    int ac = 2;
    char *av[] = {NULL, "tests/error3.txt"};
    char *buffer = read_posi("tests/error3.txt");
    int got = error(ac, av, buffer);
    int expected = 84;

    cr_assert_eq(got, expected);
}