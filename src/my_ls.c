/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** my_ls.c
*/

#include "my_ls.h"

static void get_file_with_type(list_t *all, list_t **files, list_t **dirs)
{
    file_t *file;

    while (all != NULL) {
        file = (file_t *)(all->data);
        if (file->type == FILE_TYPE)
            my_append_to_list(files, all->data);
        else
            my_append_to_list(dirs, all->data);
        all = all->next;
    }
}

static void print_all(list_t *files, flag_t flags, padding_t padding)
{
    file_t *file;

    while (files != NULL) {
        file = (file_t *)(files->data);
        files = files->next;
        print_file_path(file, flags, padding);
    }
}

static int print_files_dir(list_t *files, list_t *dirs,
    flag_t flags, padding_t padding)
{
    int print_filepath;
    int print_newline = (files != NULL);
    file_t *file;
    int output = 0;

    print_filepath = (dirs != NULL && (files != NULL || dirs->next != NULL));
    while (files != NULL) {
        file = (file_t *)(files->data);
        files = files->next;
        print_file_path(file, flags, padding);
    } while (dirs != NULL) {
        file = (file_t *)(dirs->data);
        dirs = dirs->next;
        if (print_newline)
            my_putchar('\n');
        if (!print_dir_content(file->path, flags, print_filepath))
            output = 84;
        print_newline = 1;
    }
    return (output);
}

int my_ls(list_t *files, flag_t flags)
{
    list_t *file_list = NULL;
    list_t *dir_list = NULL;
    padding_t padding;
    int output = 0;

    set_up_list(files, flags);
    if (flags.list[D_LOWER]) {
        get_padding(files, &padding, ALL_TYPES);
        print_all(files, flags, padding);
    } else {
        get_padding(files, &padding, FILE_TYPE);
        get_file_with_type(files, &file_list, &dir_list);
        output = print_files_dir(file_list, dir_list, flags, padding);
        my_free_list(&file_list, 0);
        my_free_list(&dir_list, 0);
    }
    free(flags.list);
    return (output);
}