/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** print_user_group.c
*/

#include "my_ls.h"

void print_user(uid_t id, int padding)
{
    struct passwd *user = getpwuid(id);
    int i = 0;

    if (user == NULL)
        return;
    my_putstr(user->pw_name);
    while (i < padding - my_strlen(user->pw_name)) {
        my_putchar(' ');
        i += 1;
    }
}

void print_group(gid_t id, int padding)
{
    struct group *group = getgrgid(id);
    int i = 0;

    if (group == NULL)
        return;
    my_putstr(group->gr_name);
    while (i < padding - my_strlen(group->gr_name)) {
        my_putchar(' ');
        i += 1;
    }
}