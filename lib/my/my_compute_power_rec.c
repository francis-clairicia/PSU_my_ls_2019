/*
** EPITECH PROJECT, 2019
** Power Rec
** File description:
** Returns the power of a number
*/

#include "my.h"

int my_compute_power_rec(int nb, int p)
{
    int power_down = 0;

    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    power_down = my_compute_power_rec(nb, p - 1);
    if (power_down == 0)
        return (0);
    if (nb > 0 && nb > 2147483647 / power_down)
        return (0);
    if (nb < 0 && power_down < 0 && nb < -2147483648 / (-power_down))
        return (0);
    return (nb * power_down);
}
