/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** set_up_list.c
*/

#include "my_ls.h"

void init_list(list_t **files, flag_t flags)
{
    if (flags.list[D_LOWER]) {
        if (flags.list[T_LOWER])
            sort_files(*files, SORT_BY_MODIFICATIONS);
        else
            sort_files(*files, SORT_BY_ASCII);
    } else {
        if (flags.list[T_LOWER])
            sort_files_by_type(*files, SORT_BY_MODIFICATIONS);
        else
            sort_files_by_type(*files, SORT_BY_ASCII);
    }
    if (flags.list[R_LOWER])
        my_rev_list(files);
}

void set_up_list(list_t **files, flag_t flags)
{
    if (flags.list[T_LOWER])
        sort_files(*files, SORT_BY_MODIFICATIONS);
    else
        sort_files(*files, SORT_BY_ASCII);
    if (flags.list[R_LOWER])
        my_rev_list(files);
}