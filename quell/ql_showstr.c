/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** ql_showstr.c
*/

#include "ql_base.h"
#include "ql_string.h"

void ql_puthex(int line, int pad)
{
    int len = 0;

    for (int copy = line; copy; copy /= BASE_16_LEN)
        len++;
    for (int n = pad - len; n; --n)
        ql_putchar('0');
    if (line)
        ql_putnbr_base(line, "0123456789abcdef");
}

int ql_showstr(char const *str)
{
    for (; *str != '\0'; str++) {
        if (IS_PRINT(*str))
            ql_putchar(*str);
        else {
            ql_putchar('\\');
            ql_puthex((int)(*str), 2);
        }
    }
    return 0;
}
