/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** main.c
*/

#include "my_ls.h"

int main(int ac, char **av)
{
    flag_t flags;
    list_t *files = NULL;
    int nb_flags = get_flags(ac, av, &flags);
    int nb_files = ac - 1 - nb_flags;

    if (nb_flags < 0)
        return (84);
    files = get_files_and_folders(ac, av, nb_files);
    if (files == NULL)
        return (84);
    init_list(&files, flags);
    my_ls(files, flags);
    free_files_list(&files);
    return (0);
}