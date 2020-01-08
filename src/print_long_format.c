/*
** EPITECH PROJECT, 2019
** bonus
** File description:
** print_long_format.c
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

void print_long_format(file_t *file, char const *to_print,
    padding_t padding)
{
    print_infos(&(file->infos), padding);
    my_putstr(to_print);
    if (S_ISLNK(file->infos.st_mode))
        print_link(file->path, file->infos.st_size);
}