/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** test_print_permissions_dev.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_ls.h"

Test(print_permissions, print_block_device_file_permissions)
{
    struct stat infos;

    cr_redirect_stdout();
    cr_assert_neq(stat("/dev/sda", &infos), -1);
    print_permissions(infos.st_mode);
    cr_expect_stdout_eq_str("brw-rw-""-""-""-");
}

Test(print_permissions, print_char_device_file_permissions)
{
    struct stat infos;

    cr_redirect_stdout();
    cr_assert_neq(stat("/dev/tty", &infos), -1);
    print_permissions(infos.st_mode);
    cr_expect_stdout_eq_str("crw-rw-rw-");
}