/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** my_putstr_error.c
*/

#include "my_ls.h"

void my_putstr_error(char const *str)
{
    int len = my_strlen(str);

    write(2, str, len);
}