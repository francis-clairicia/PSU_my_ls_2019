/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** sort_files.c
*/

#include "my_ls.h"

static list_t *is_sorted(list_t *files, enum SORTING_METHODS method)
{
    file_t *first;
    file_t *second;
    int (*sorting_functions[])(file_t *, file_t *) = {
        &sorted_by_ascii,
        &sorted_by_modifications
    };
    int (*sorted)(file_t *, file_t *) = sorting_functions[method];

    while (files->next != NULL) {
        first = (file_t *)(files->data);
        second = (file_t *)(files->next->data);
        if (!sorted(first, second))
            return (files);
        files = files->next;
    }
    return (NULL);
}

static void swap(file_t *first, file_t *second)
{
    char *path = second->path;
    char *name = second->name;
    int type = second->type;
    struct stat infos = second->infos;

    second->path = first->path;
    second->name = first->name;
    second->type = first->type;
    second->infos = first->infos;
    first->path = path;
    first->name = name;
    first->type = type;
    first->infos = infos;
}

void sort_files(list_t *files, enum SORTING_METHODS method)
{
    file_t *first;
    file_t *second;
    list_t *node;

    if (files == NULL)
        return;
    while ((node = is_sorted(files, method)) != NULL) {
        first = (file_t *)(node->data);
        second = (file_t *)(node->next->data);
        swap(first, second);
    }
}