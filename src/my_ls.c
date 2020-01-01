/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** my_ls.c
*/

#include "my_ls.h"

static void print_list(list_t *files, flag_t flags, padding_t padding)
{
    int first_print = 1;
    int print_filepath = (flags.list[R_UPPER] || files->next != NULL);
    file_t *file;

    while (files != NULL) {
        file = (file_t *)(files->data);
        files = files->next;
        if (file->type == FILE_TYPE ||
        (file->type == DIR_TYPE && flags.list[D_LOWER])) {
            print_file_path(file, flags, padding);
            first_print = 0;
            continue;
        }
        if (!first_print)
            my_putchar('\n');
        print_dir_content(file->path, flags, print_filepath);
        first_print = 0;
    }
}

void my_ls(list_t *files, flag_t flags)
{
    padding_t padding;

    init_list(files, flags);
    if (flags.list[D_LOWER])
        get_padding(files, &padding, ALL_TYPES);
    else
        get_padding(files, &padding, FILE_TYPE);
    print_list(files, flags, padding);
    free(flags.list);
}