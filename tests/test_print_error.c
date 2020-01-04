/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** test_print_error.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_ls.h"

Test(my_putstr_error, write_in_stderr)
{
    cr_redirect_stderr();
    my_putstr_error("Hello");
    cr_expect_stderr_eq_str("Hello");
}

Test(print_error_access, write_in_stderr)
{
    cr_redirect_stderr();
    print_error_access("unknown", "No such file or directory");
    cr_expect_stderr_eq_str("./my_ls: cannot access 'unknown': "
        "No such file or directory\n");
}

Test(print_error_open, write_in_stderr)
{
    cr_redirect_stderr();
    print_error_open("/root", "Permission denied");
    cr_expect_stderr_eq_str("./my_ls: cannot open directory '/root': "
        "Permission denied\n");
}