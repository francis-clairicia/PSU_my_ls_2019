/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** print_infos.c
*/

#include "my_ls.h"

void print_number(long nb, int padding)
{
    int i = 0;
    int len = my_nbr_len(nb);

    my_put_nbr(nb);
    while (i < padding - len) {
        my_putchar(' ');
        i += 1;
    }
}

void print_infos(struct stat *infos, padding_t padding)
{
    print_permissions(infos->st_mode);
    my_putchar(' ');
    print_number((long)infos->st_nlink, padding.nlink);
    my_putchar(' ');
    print_user(infos->st_uid, padding.user);
    my_putchar(' ');
    print_group(infos->st_gid, padding.group);
    my_putchar(' ');
    if (S_ISBLK(infos->st_mode) || S_ISCHR(infos->st_mode))
        print_major_minor(infos->st_rdev, padding.maj_v, padding.min_v);
    else
        print_number((long)infos->st_size, padding.size);
    my_putchar(' ');
    print_time(infos->st_mtime);
    my_putchar(' ');
}