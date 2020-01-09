/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** test_print_permissions_special.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_ls.h"

Test(print_permissions, print_sticky_bit_file_non_executable)
{
    struct stat infos;

    cr_redirect_stdout();
    cr_assert_neq(stat("tests/.test_files/sticky_bit_non_exec", &infos), -1);
    print_permissions(infos.st_mode);
    cr_expect_stdout_eq_str("-rw-rw-r-T");
}

Test(print_permissions, print_sticky_bit_file_executable)
{
    struct stat infos;

    cr_redirect_stdout();
    cr_assert_neq(stat("tests/.test_files/sticky_bit_exec", &infos), -1);
    print_permissions(infos.st_mode);
    cr_expect_stdout_eq_str("-rwxrwxr-t");
}

Test(print_permissions, print_set_uid_gid_file_non_executable)
{
    struct stat infos;
    char file[] = "tests/.test_files/set_uid_gid_file_non_exec";

    cr_redirect_stdout();
    cr_assert_neq(stat(file, &infos), -1);
    print_permissions(infos.st_mode);
    cr_expect_stdout_eq_str("-rwSrwSr--");
}

Test(print_permissions, print_set_uid_gid_file_executable)
{
    struct stat infos;
    char file[] = "tests/.test_files/set_uid_gid_file_exec";

    cr_redirect_stdout();
    cr_assert_neq(stat(file, &infos), -1);
    print_permissions(infos.st_mode);
    cr_expect_stdout_eq_str("-rwsrwsr-x");
}