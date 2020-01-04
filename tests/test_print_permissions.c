/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** test_print_permissions.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_ls.h"

Test(print_permissions, print_file_permissions)
{
    struct stat infos;

    cr_redirect_stdout();
    cr_assert_neq(stat("main.c", &infos), -1);
    print_permissions(infos.st_mode);
    cr_expect_stdout_eq_str("-rw-rw-r--");
}

Test(print_permissions, print_directory_permissions)
{
    struct stat infos;

    cr_redirect_stdout();
    cr_assert_neq(stat("src/", &infos), -1);
    print_permissions(infos.st_mode);
    cr_expect_stdout_eq_str("drwxrwxr-x");
}

Test(print_permissions, print_symbolik_link_permissions)
{
    struct stat infos;

    cr_redirect_stdout();
    cr_assert_neq(lstat("link_main.c", &infos), -1);
    print_permissions(infos.st_mode);
    cr_expect_stdout_eq_str("lrwxrwxrwx");
}

Test(print_permissions, print_char_device_file_permissions)
{
    struct stat infos;

    cr_redirect_stdout();
    cr_assert_neq(stat("/dev/tty", &infos), -1);
    print_permissions(infos.st_mode);
    cr_expect_stdout_eq_str("crw-rw-rw-");
}

Test(print_permissions, print_fifo_file_permissions)
{
    struct stat infos;

    cr_redirect_stdout();
    cr_assert_neq(stat("pipe_file.c", &infos), -1);
    print_permissions(infos.st_mode);
    cr_expect_stdout_eq_str("prw-rw-r-t");
}