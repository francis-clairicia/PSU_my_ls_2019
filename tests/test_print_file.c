/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** test_print_file.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_ls.h"

Test(print_file, print_a_file)
{
    flag_t flags = {5, {0, 0, 0, 0, 0}};
    padding_t padding = {0, 0, 0, 0};
    file_t file;

    cr_redirect_stdout();
    flags.list[FLAG_L_LOWER] = 1;
    get_file_infos("include/my.h", &file);
    print_file_name(&file, flags, padding);
    print_file_path(&file, flags, padding);
    cr_expect_stdout_neq_str("my.h\ninclude/my.h\n");
}

Test(print_file, print_a_link)
{
    flag_t flags = {5, {0, 0, 0, 0, 0}};
    padding_t padding = {0, 0, 0, 0};
    file_t file;

    cr_redirect_stdout();
    flags.list[FLAG_L_LOWER] = 1;
    get_file_infos("link_main.c", &file);
    print_file_name(&file, flags, padding);
    print_file_path(&file, flags, padding);
    cr_expect_stdout_neq_str("link_main.c\n");
}
