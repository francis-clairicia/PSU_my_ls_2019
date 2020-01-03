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
    flag_t flags;

    cr_redirect_stdout();
    get_flags(1, (char *[]){"-R"}, &flags);
    print_dir_content("lib/", flags, 1);
    cr_expect_stdout_neq_str("\n");
    free(flags.list);
}