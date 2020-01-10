/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** print_dir_content.c
*/

#include "my_ls.h"

static void print_filepath_at_beginning(char const *filepath, flag_t flags,
    int print_filepath)
{
    if (print_filepath || flags.list[R_UPPER]) {
        my_putstr(filepath);
        my_putstr(":\n");
    }
}

static void print_total_block(list_t *files)
{
    file_t *file;
    long total = 0;

    while (files != NULL) {
        file = (file_t *)(files->data);
        files = files->next;
        total += file->infos.st_blocks;
    }
    total /= 2;
    my_putstr("total ");
    my_put_nbr(total);
    my_putchar('\n');
}

static void print_all_content(list_t *files, flag_t flags, padding_t padding)
{
    file_t *file;

    if (flags.list[L_LOWER])
        print_total_block(files);
    while (files != NULL) {
        file = (file_t *)(files->data);
        files = files->next;
        print_file_name(file, flags, padding);
    }
}

static int print_subdirectories(list_t *files, flag_t flags)
{
    file_t *file;
    int output = 1;

    while (files != NULL) {
        file = (file_t *)(files->data);
        files = files->next;
        if (file->type == DIR_TYPE) {
            my_putchar('\n');
            if (!print_dir_content(file->path, flags, 1))
                output = 0;
        }
    }
    return (output);
}

int print_dir_content(char const *filepath, flag_t flags, int print_filepath)
{
    list_t *files = NULL;
    DIR *dirp = opendir(filepath);
    padding_t padding;
    int output = 1;

    if (dirp == NULL)
        return (print_error_open(filepath, strerror(errno)));
    if (get_files_from_dir(&files, dirp, filepath)) {
        print_filepath_at_beginning(filepath, flags, print_filepath);
        set_up_list(files, flags);
        get_padding(files, &padding, ALL_TYPES);
        print_all_content(files, flags, padding);
        if (flags.list[R_UPPER])
            output = print_subdirectories(files, flags);
    }
    closedir(dirp);
    free_files_list(&files);
    return (output);
}