/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** sorting_methods.c
*/

#include "my_ls.h"

int sorted_by_ascii(file_t *first, file_t *second, int ignore_type)
{
    if (!ignore_type && first->type == DIR_TYPE && second->type == FILE_TYPE)
        return (0);
    if (ignore_type || (!ignore_type && first->type == second->type))
        return (my_strcmp(first->path, second->path) < 1);
    return (1);
}

int sorted_by_modifications(file_t *first, file_t *second, int ignore_type)
{
    if (!ignore_type && first->type == DIR_TYPE && second->type == FILE_TYPE)
        return (0);
    if (ignore_type || (!ignore_type && first->type == second->type))
        return (first->infos.st_mtime >= second->infos.st_mtime);
    return (1);
}