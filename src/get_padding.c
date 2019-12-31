/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** get_padding.c
*/

#include "my_ls.h"

static void check_padding(padding_t *padding, struct stat *infos)
{
    struct passwd *user = getpwuid(infos->st_uid);
    struct group *group = getgrgid(infos->st_gid);

    padding->nlink = MAX(padding->nlink, my_nbr_len((long)infos->st_nlink));
    if (user != NULL)
        padding->user = MAX(padding->user, my_strlen(user->pw_name));
    if (group != NULL)
        padding->group = MAX(padding->group, my_strlen(group->gr_name));
    padding->size = MAX(padding->size, my_nbr_len((long)infos->st_size));
}

void get_padding(list_t *files, padding_t *padding, int type)
{
    file_t *file;

    padding->nlink = 0;
    padding->user = 0;
    padding->group = 0;
    padding->size = 0;
    while (files != NULL) {
        file = (file_t *)(files->data);
        files = files->next;
        if (type == ALL_TYPES || file->type == type)
            check_padding(padding, &(file->infos));
    }
}