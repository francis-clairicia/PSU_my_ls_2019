/*
** EPITECH PROJECT, 2019
** bonus
** File description:
** get_files_from_dir.c
*/

#include "my_ls.h"

int get_files_from_dir(list_t **list, DIR *dirp, char const *current_filepath)
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