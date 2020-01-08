/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** print_major_minor.c
*/

#include "my_ls.h"

void print_major_minor(dev_t dev_id, int padding_maj, int padding_min)
{
    print_number(major(dev_id), padding_maj);
    my_putstr(", ");
    print_number(minor(dev_id), padding_min);
}