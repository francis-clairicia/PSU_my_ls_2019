/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** free_files_list.c
*/

#include "my_ls.h"

void free_files_list(list_t **files)
{
    list_t *node = *files;
    file_t *file;

    while (node != NULL) {
        file = (file_t *)(node->data);
        node = node->next;
        free(file->path);
    }
    my_free_list(files, 1);
}