/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** ql_showmem.c
*/

#include "ql_base.h"
#include "ql_string.h"

static
void ql_show_memblock(char const *mem, int n)
{
    int leftover = BASE_16_LEN - n;
    int group = BASE_16_LEN;

    ql_putstr(": ");
    for (; n; n--) {
        ql_puthex((int)(unsigned char)*mem++, 2);
        if (group & 1)
            ql_putchar(' ');
        group--;
    }
    for (; leftover; leftover--) {
        ql_putstr("  ");
        if (group & 1)
            ql_putchar(' ');
        group--;
    }
}

static
void ql_show_ascii(char const *mem, int n)
{
    for (; n--; mem++)
        ql_putchar(IS_PRINT(*mem) ? *mem : '.');
}

int ql_showmem(char const *str, int size)
{
    char const *p = str;

    for (; size > 0; p += BASE_16_LEN) {
        ql_puthex(p - str, BASE_16_LEN << 1);
        ql_show_memblock(p, MIN(16, size));
        ql_show_ascii(p, MIN(16, size));
        ql_putchar('\n');
        size -= 16;
    }
    return 0;
}
