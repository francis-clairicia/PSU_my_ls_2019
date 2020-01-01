/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** get_files_and_folders.c
*/

#include "my_ls.h"

static int get_infos_from_args(int ac, char **av, list_t **files)
{
    int i = 0;
    file_t *file;

    while (i < ac) {
        if (av[i][0] == '-') {
            i += 1;
            continue;
        }
        file = malloc(sizeof(file_t));
        if (file == NULL || !get_file_infos(av[i], file)) {
            free(file);
            return (0);
        }
        my_append_to_list(files, (long)file);
        i += 1;
    }
    return (1);
}

static int get_infos(int ac, char **av, list_t **files, int nb_files)
{
    int status = 1;
    char *default_folder[] = {"."};

    if (nb_files == 0) {
        status = get_infos_from_args(1, default_folder, files);
    } else
        status = get_infos_from_args(ac, av, files);
    return (status);
}

list_t *get_files_and_folders(int ac, char **av, flag_t flags)
{
    int nb_files = ac - 1 - flags.nb;
    list_t *files = NULL;

    if (!get_infos(ac - 1, &av[1], &files, nb_files)) {
        free(flags.list);
        free_files_list(&files);
        return (NULL);
    }
    return (files);
}