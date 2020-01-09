/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** get_files_and_folders.c
*/

#include "my_ls.h"

static int get_infos_from_args(int ac, char **av, list_t **files, int *output)
{
    int i = 0;
    file_t *file;

    while (i < ac) {
        if (av[i][0] == '-') {
            i += 1;
            continue;
        }
        file = malloc(sizeof(file_t));
        if (file != NULL && !get_file_infos(av[i], file)) {
            free(file);
            *output = 84;
        } else if (file != NULL)
            my_append_to_list(files, (long)file);
        i += 1;
    }
    return (*files != NULL);
}

list_t *get_files_and_folders(int ac, char **av, flag_t flags, int *output)
{
    int args_size = ac - 1;
    char **args = &av[1];
    int nb_files = args_size - flags.nb;
    list_t *files = NULL;

    if (nb_files == 0) {
        args_size = 1;
        args = (char *[]){"."};
    }
    if (!get_infos_from_args(args_size, args, &files, output)) {
        free(flags.list);
        free_files_list(&files);
        return (NULL);
    }
    return (files);
}