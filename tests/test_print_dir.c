/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** test_print_dir.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_ls.h"

Test(print_dir_content, special_case)
{
    flag_t flags = {5, {0, 0, 0, 0, 0}};

    cr_redirect_stdout();
    flags.list[FLAG_R_UPPER] = 1;
    print_dir_content("lib/", flags, 1);
    cr_expect_stdout_neq_str("\n");
}