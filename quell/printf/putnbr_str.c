/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** putnbr_str.c
*/

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include "ql_base.h"

__attribute__((used))
static const char *BASE_CHARSET = "0123456789abcdef";

static
int intlen(intmax_t i)
{
    int n = 1;

    for (i /= 10; i != 0; i /= 10)
        n++;
    return n;
}

int putnbr_str(char *s, intmax_t n)
{
    int size = 0;

    if (n >= 0)
        n = -n;
    size += intlen(n);
    for (int i = intlen(n); i != 0; n /= 10) {
        i--;
        s[i] = -(n % 10) | '0';
    }
    return size;
}

int base_len(int base, size_t n)
{
    int i = 1;

    for (n /= base; n != 0; n /= base)
        i++;
    return i;
}

int putnbr_base_str(char *s, size_t base, size_t n)
{
    int len = base_len(base, n);

    for (int i = len; i > 0; n /= base) {
        i--;
        s[i] = BASE_CHARSET[n % base];
    }
    return len;
}
