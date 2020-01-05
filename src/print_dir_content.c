/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** print_dir_content.c
*/

#include "my_ls.h"

static int get_files(list_t **list, DIR *dirp, char const *current_filepath)
{
    file_t *file;
    struct dirent *ent;
    char *filepath;

    while ((ent = readdir(dirp)) != NULL) {
        file = malloc(sizeof(file_t));
        if (file == NULL)
            return (0);
        if (ent->d_name[0] != '.') {
            filepath = join_path(current_filepath, ent->d_name);
            get_file_infos(filepath, file);
            my_append_to_list(list, (long)file);
            free(filepath);
        } else {
            free(file);
        }
    }
    return (1);
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

static void print_subdirectories(list_t *files, flag_t flags)
{
    file_t *file;

    while (files != NULL) {
        file = (file_t *)(files->data);
        files = files->next;
        if (file->type == DIR_TYPE) {
            my_putchar('\n');
            print_dir_content(file->path, flags, 1);
        }
    }
}

void print_dir_content(char const *filepath, flag_t flags, int print_filepath)
{
    list_t *files = NULL;
    DIR *dirp = opendir(filepath);
    padding_t padding;

    if (dirp == NULL)
        return (print_error_open(filepath, strerror(errno)));
    if (get_files(&files, dirp, filepath)) {
        if (print_filepath) {
            my_putstr(filepath);
            my_putstr(":\n");
        }
        set_up_list(files, flags);
        get_padding(files, &padding, ALL_TYPES);
        print_all_content(files, flags, padding);
        if (flags.list[R_UPPER])
            print_subdirectories(files, flags);
    }
    closedir(dirp);
    free_files_list(&files);
}