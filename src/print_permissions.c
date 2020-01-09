/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** print_permissions.c
*/

#include "my_ls.h"

static char filetype(mode_t mode)
{
    if (S_ISBLK(mode))
        return ('b');
    if (S_ISCHR(mode))
        return ('c');
    if (S_ISSOCK(mode))
        return ('s');
    if (S_ISLNK(mode))
        return ('l');
    if (S_ISFIFO(mode))
        return ('p');
    if (S_ISDIR(mode))
        return ('d');
    if (S_ISREG(mode))
        return ('-');
    return ('?');
}

void print_permissions(mode_t mode)
{
    my_putchar(filetype(mode));
    my_putchar((mode & S_IRUSR) ? 'r' : '-');
    my_putchar((mode & S_IWUSR) ? 'w' : '-');
    if (mode & S_ISUID)
        my_putchar((mode & S_IXUSR) ? 's' : 'S');
    else
        my_putchar((mode & S_IXUSR) ? 'x' : '-');
    my_putchar((mode & S_IRGRP) ? 'r' : '-');
    my_putchar((mode & S_IWGRP) ? 'w' : '-');
    if (mode & S_ISGID)
        my_putchar((mode & S_IXGRP) ? 's' : 'S');
    else
        my_putchar((mode & S_IXGRP) ? 'x' : '-');
    my_putchar((mode & S_IROTH) ? 'r' : '-');
    my_putchar((mode & S_IWOTH) ? 'w' : '-');
    if (mode & S_ISVTX)
        my_putchar((mode & S_IXOTH) ? 't' : 'T');
    else
        my_putchar((mode & S_IXOTH) ? 'x' : '-');
}