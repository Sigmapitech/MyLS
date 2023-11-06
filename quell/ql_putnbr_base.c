/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** ql_putnbr_base.c
*/

#include "ql_base.h"
#include "ql_string.h"

static
void ql_putpos_base(int nbr, char const *base, int base_length)
{
    if (nbr >= base_length)
        ql_putpos_base(nbr / base_length, base, base_length);
    ql_putchar(base[nbr % base_length]);
}

int ql_putnbr_base(int nbr, char const *base)
{
    int div = ql_strlen(base);
    int abs_n = (nbr >= 0) ? nbr : -nbr;

    if (nbr < 0)
        ql_putchar('-');
    if (abs_n >= 0) {
        ql_putpos_base(abs_n, base, div);
        return 0;
    }
    ql_putpos_base(-(nbr / div), base, div);
    ql_putchar(base[-(nbr % div)]);
    return 0;
}
