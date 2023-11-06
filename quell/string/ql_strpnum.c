/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** ql_strpnum.c
*/

#include <limits.h>
#include "ql_string.h"

int ql_strpnum(char **strp)
{
    char *s = *strp;
    int n = 0;

    for (; IS_DIGIT(*s); s++) {
        if (n > ((INT_MAX / 10) - (*s & ~'0')))
            return -1;
        n = n * 10 + (*s & ~'0');
    }
    if (!n && s == *strp)
        return -1;
    *strp = s;
    return n;
}
