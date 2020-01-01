/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** test_get_flags.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_ls.h"

Test(get_flags, analyse_flags_in_argv)
{
    int argc = 4;
    char *argv[] = {"./my_ls", "folder", "-l", "-R"};
    flag_t flags;

    cr_assert_eq(get_flags(argc, argv, &flags), 1);
    cr_expect_eq(flags.nb, 2);
    cr_expect_eq(flags.list[L_LOWER], 1);
    cr_expect_eq(flags.list[R_UPPER], 1);
    free(flags.list);
}

Test(get_flags, handle_multiple_char_in_flag)
{
    int argc = 4;
    char *argv[] = {"./my_ls", "s", "-lt", "-Rr"};
    flag_t flags;

    cr_assert_eq(get_flags(argc, argv, &flags), 1);
    cr_expect_eq(flags.nb, 2);
    cr_expect_eq(flags.list[L_LOWER], 1);
    cr_expect_eq(flags.list[R_UPPER], 1);
    cr_expect_eq(flags.list[R_LOWER], 1);
    cr_expect_eq(flags.list[T_LOWER], 1);
    free(flags.list);
}

Test(get_flags, handle_unknown_flag)
{
    int argc = 3;
    char *argv[] = {"./my_ls", "-l", "-z"};
    flag_t flags;

    cr_redirect_stderr();
    cr_expect_eq(get_flags(argc, argv, &flags), 0);
    cr_expect_stderr_eq_str("./my_ls: invalid option: z\n");
}