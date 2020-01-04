/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** print_file.c
*/

#include <linux/limits.h>
#include "my_ls.h"

static void print_link(char const *filepath, off_t st_size)
{
    int size = (st_size == 0) ? PATH_MAX : st_size;
    char buffer[size + 1];

    size = readlink(filepath, buffer, size);
    if (size >= 0) {
        buffer[size] = '\0';
        my_putstr(" -> ");
        my_putstr(buffer);
    }
}

static void print_file(file_t *file, char const *to_print,
    flag_t flags, padding_t padding)
{
    if (flags.list[L_LOWER] == 1)
        print_infos(&(file->infos), padding);
    my_putstr(to_print);
    if (flags.list[L_LOWER] == 1 && S_ISLNK(file->infos.st_mode))
        print_link(file->path, file->infos.st_size);
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