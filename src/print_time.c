/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** print_time.c
*/

#include "my_ls.h"

void print_time(time_t time)
{
    char **date = my_str_to_word_array(ctime(&time));

    if (date == NULL)
        return;
    my_putstr(date[1]);
    my_putchar(' ');
    if (my_strlen(date[2]) == 1)
        my_putchar(' ');
    my_putstr(date[2]);
    my_putchar(' ');
    my_putstr(date[3]);
    my_putchar(':');
    my_putstr(date[4]);
    my_free_word_array(date);
}