/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** ql_strcpy.c
*/

#include "ql_string.h"

char *ql_strcpy(char *dest, char const *src)
{
    for (; *src != '\0'; src++) {
        *dest = *src;
        dest++;
    }
    *dest = '\0';
    return dest;
}

char *ql_strncpy(char *dest, char const *src, int n)
{
    char *destp = dest;

    for (; n > 0 && *src != '\0'; --n) {
        *dest = *src;
        src++;
        dest++;
    }
    if (n)
        *dest = '\0';
    return destp;
}
