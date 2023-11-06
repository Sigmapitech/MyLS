/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** ql_putnbr.c
*/

#include "ql_base.h"

static
int cycle_negative(int n)
{
    int reduced = -(n / 10);

    ql_putchar('-');
    if (reduced)
        ql_putnbr(reduced);
    return -(n % 10);
}

int ql_putnbr(int n)
{
    if (n < 0)
        n = cycle_negative(n);
    if (n > 9)
        ql_putnbr(n / 10);
    ql_putchar((n % 10) | '0');
    return 0;
}
