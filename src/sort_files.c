/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** sort_files.c
*/

#include "my_ls.h"

static int (*sorting_functions[])(file_t *, file_t *, int) = {
    &sorted_by_ascii,
    &sorted_by_modifications
};

static list_t *is_sorted(list_t *files, enum SORTING_METHODS method,
    int ignore_type)
{
    file_t *first;
    file_t *second;
    int (*sorted)(file_t *, file_t *, int) = sorting_functions[method];

    while (files->next != NULL) {
        first = (file_t *)(files->data);
        second = (file_t *)(files->next->data);
        if (!sorted(first, second, ignore_type))
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

void sort_files_list(list_t *files, enum SORTING_METHODS method,
    int ignore_type)
{
    file_t *first;
    file_t *second;
    list_t *node;

    while ((node = is_sorted(files, method, ignore_type)) != NULL) {
        first = (file_t *)(node->data);
        second = (file_t *)(node->next->data);
        swap(first, second);
    }
}