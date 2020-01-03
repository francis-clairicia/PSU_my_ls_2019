/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** print_permissions.c
*/

#include "my_ls.h"

static char filetype(mode_t mode)
{
    char type = '-';

    if (S_ISDIR(mode))
        type = 'd';
    if (S_ISLNK(mode))
        type = 'l';
    if (S_ISFIFO(mode))
        type = 'p';
    if (S_ISCHR(mode))
        type = 'c';
    return (type);
}

void print_permissions(mode_t mode)
{
    my_putchar(filetype(mode));
    my_putchar((mode & S_IRUSR) ? 'r' : '-');
    my_putchar((mode & S_IWUSR) ? 'w' : '-');
    my_putchar((mode & S_IXUSR) ? 'x' : '-');
    my_putchar((mode & S_IRGRP) ? 'r' : '-');
    my_putchar((mode & S_IWGRP) ? 'w' : '-');
    my_putchar((mode & S_IXGRP) ? 'x' : '-');
    my_putchar((mode & S_IROTH) ? 'r' : '-');
    my_putchar((mode & S_IWOTH) ? 'w' : '-');
    if (mode & S_ISVTX)
        my_putchar('t');
    else
        my_putchar((mode & S_IXOTH) ? 'x' : '-');
}