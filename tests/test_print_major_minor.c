/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** test_print_major_minor.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_ls.h"

Test(print_major_minor, print_major_minor_instead_of_size)
{
    struct stat infos;

    cr_redirect_stdout();
    cr_assert_neq(stat("/dev/tty", &infos), -1);
    print_major_minor(infos.st_rdev, 0, 0);
    cr_expect_stdout_eq_str("5, 0");
}