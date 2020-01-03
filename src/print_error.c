/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** print_error.c
*/

#include "my_ls.h"

int print_error_access(char const *filepath)
{
    my_putstr_error("./my_ls: cannot access '");
    my_putstr_error(filepath);
    perror("'");
    return (0);
}

void print_error_open(char const *filepath)
{
    my_putstr_error("./my_ls: cannot open directory '");
    my_putstr_error(filepath);
    perror("'");
}