/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** ql_strcpy.c
*/

#include "ql_string.h"

char *ql_strcpy(char *dest, char const *src)
{
    while (*src != '\0')
        *dest++ = *src++;
    *dest = '\0';
    return dest;
}

char *ql_strncpy(char *dest, char const *src, int n)
{
    for (; n > 0 && *src != '\0'; --n)
        *dest++ = *src++;
    if (n)
        *dest = '\0';
    return dest;
}
