/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** test_my_putstr_error.c
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