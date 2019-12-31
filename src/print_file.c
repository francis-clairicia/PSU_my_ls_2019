/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** print_file.c
*/

#include <linux/limits.h>
#include "my_ls.h"

static void print_link(file_t *file)
{
    int size = (file->infos.st_size == 0) ? PATH_MAX : file->infos.st_size;
    char *buffer = malloc(sizeof(char) * (size + 1));

    if (buffer == NULL)
        return;
    size = readlink(file->path, buffer, size);
    if (size >= 0) {
        buffer[size] = '\0';
        my_putstr(" -> ");
        my_putstr(buffer);
    }
    free(buffer);
}

void print_file_path(file_t *file, flag_t flags, padding_t padding)
{
    if (flags.list[FLAG_L_LOWER] == 1)
        print_infos(&(file->infos), padding);
    my_putstr(file->path);
    if (flags.list[FLAG_L_LOWER] == 1 && S_ISLNK(file->infos.st_mode))
        print_link(file);
    my_putchar('\n');
}

void print_file_name(file_t *file, flag_t flags, padding_t padding)
{
    if (flags.list[FLAG_L_LOWER] == 1)
        print_infos(&(file->infos), padding);
    my_putstr(file->name);
    if (flags.list[FLAG_L_LOWER] == 1 && S_ISLNK(file->infos.st_mode))
        print_link(file);
    my_putchar('\n');
}