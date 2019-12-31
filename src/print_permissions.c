/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** print_permissions.c
*/

#include "my_ls.h"

void print_permissions(mode_t mode)
{
    if (S_ISLNK(mode))
        my_putchar('l');
    else
        my_putchar((S_ISDIR(mode)) ? 'd' : '-');
    my_putchar((mode & S_IRUSR) ? 'r' : '-');
    my_putchar((mode & S_IWUSR) ? 'w' : '-');
    my_putchar((mode & S_IXUSR) ? 'x' : '-');
    my_putchar((mode & S_IRGRP) ? 'r' : '-');
    my_putchar((mode & S_IWGRP) ? 'w' : '-');
    my_putchar((mode & S_IXGRP) ? 'x' : '-');
    my_putchar((mode & S_IROTH) ? 'r' : '-');
    my_putchar((mode & S_IWOTH) ? 'w' : '-');
    my_putchar((mode & S_IXOTH) ? 'x' : '-');
}