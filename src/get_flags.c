/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** get_flags.c
*/

#include "my_ls.h"

static const struct flag_format flag_list[] = {
    {'l', L_LOWER},
    {'r', R_LOWER},
    {'R', R_UPPER},
    {'d', D_LOWER},
    {'t', T_LOWER},
    {'\0', UNKNOWN_FLAG}
};

static int find_in_flag_list(char letter)
{
    int i = 0;

    while (flag_list[i].letter != '\0') {
        if (flag_list[i].letter == letter)
            return (flag_list[i].value);
        i += 1;
    }
    return (UNKNOWN_FLAG);
}

static int init_flags(flag_t *flags)
{
    int i = 0;
    int count = 0;

    while (flag_list[count].letter != '\0')
        count += 1;
    flags->nb = 0;
    flags->list = malloc(sizeof(int) * count);
    if (flags->list == NULL)
        return (0);
    while (i < count) {
        flags->list[i] = 0;
        i += 1;
    }
    return (1);
}

static int search_flag(char *arg, flag_t *flags)
{
    int i = 1;
    int flag = 0;

    if (my_strlen(arg) < 2 || arg[0] != '-')
        return (0);
    while (arg[i] != '\0') {
        flag = find_in_flag_list(arg[i]);
        if (flag == UNKNOWN_FLAG) {
            my_putstr_error("./my_ls: invalid option: ");
            write(2, &arg[i], 1);
            write(2, "\n", 1);
            free(flags->list);
            return (2);
        }
        flags->list[flag] = 1;
        i += 1;
    }
    return (1);
}

int get_flags(int ac, char **av, flag_t *flags)
{
    int i = 0;
    int nb_flags = 0;
    int is_flag;

    if (!init_flags(flags))
        return (0);
    while (i < ac) {
        is_flag = search_flag(av[i], flags);
        if (is_flag == 2)
            return (0);
        nb_flags += is_flag;
        i += 1;
    }
    flags->nb = nb_flags;
    return (1);
}