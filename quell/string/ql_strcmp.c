/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** ql_strcmp.c
*/

#include "ql_string.h"

int ql_strcmp(char const *s1, char const *s2)
{
    for (; *s1 && *s1 == *s2; s1++)
        s2++;
    return *s1 - *s2;
}

int ql_strncmp(char const *s1, char const *s2, int n)
{
    if (n == 0)
        return 0;
    for (; n > 1 && *s1 && *s1 == *s2; --n) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}
