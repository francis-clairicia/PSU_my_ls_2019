/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** print_file.c
*/

#include "my_ls.h"

static void print_file(file_t *file, char const *to_print,
    flag_t flags, padding_t padding)
{
    if (flags.list[L_LOWER])
        print_long_format(file, to_print, padding);
    else
        my_putstr(to_print);
    my_putchar('\n');
}

void print_file_path(file_t *file, flag_t flags, padding_t padding)
{
    print_file(file, file->path, flags, padding);
}

void print_file_name(file_t *file, flag_t flags, padding_t padding)
{
    print_file(file, file->name, flags, padding);
}