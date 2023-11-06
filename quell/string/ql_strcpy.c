/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** ql_strcpy.c
*/

#include "ql_string.h"

char *ql_strcpy(char *dest, char const *src)
{
    char *p = dest;

    while (*src != '\0')
        *p++ = *src++;
    *p = '\0';
    return dest;
}

char *ql_strncpy(char *dest, char const *src, int n)
{
    char *p = dest;

    for (; n > 0 && *src != '\0'; --n)
        *p++ = *src++;
    if (n)
        *p = '\0';
    return dest;
}
