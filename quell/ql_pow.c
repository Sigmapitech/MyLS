/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_pow.c
*/


#include "ql_base.h"

int ql_pow(int nb, int p)
{
    int r = 1;

    if (p < 0)
        return 0;
    for (; p; p--)
        r *= nb;
    return r;
}
