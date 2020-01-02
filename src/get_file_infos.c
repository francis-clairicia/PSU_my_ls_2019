/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** get_file_infos.c
*/

#include "my_ls.h"

static char *get_filename(char *filepath)
{
    int n;

    while ((n = my_find_char(filepath, '/')) >= 0)
        filepath = &filepath[n + 1];
    return (filepath);
}

int get_file_infos(char *filepath, file_t *file)
{
    if (lstat(filepath, &(file->infos)) < 0) {
        my_putstr_error("./my_ls: cannot access '");
        my_putstr_error(filepath);
        perror("'");
        return (0);
    }
    file->path = my_strdup(filepath);
    file->name = get_filename(file->path);
    file->type = S_ISDIR(file->infos.st_mode);
    return (1);
}