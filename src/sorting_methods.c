/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** sorting_methods.c
*/

#include "my_ls.h"

static int compare_path(char const *first, char const *second)
{
    char first_copy[my_strlen(first) + 1];
    char second_copy[my_strlen(second) + 1];

    my_strlowcase(my_strcpy(first_copy, first));
    my_strlowcase(my_strcpy(second_copy, second));
    return (my_strcmp(first_copy, second_copy));
}

int sorted_by_ascii(file_t *first, file_t *second)
{
    return (compare_path(first->path, second->path) < 1);
}

int sorted_by_modifications(file_t *first, file_t *second)
{
    return (first->infos.st_mtime >= second->infos.st_mtime);
}