/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** test_print_user_group.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_ls.h"

Test(print_user, high_padding)
{
    padding_t padding = {0, 100000, 100000, 0};
    struct stat infos;

    cr_redirect_stdout();
    stat("tests/", &infos);
    print_user(infos.st_uid, padding.user);
    cr_expect_stdout_neq_str("");
}

Test(print_group, high_padding)
{
    padding_t padding = {0, 100000, 100000, 0};
    struct stat infos;

    cr_redirect_stdout();
    stat("tests/", &infos);
    print_group(infos.st_gid, padding.group);
    cr_expect_stdout_neq_str("");
}