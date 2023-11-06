/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** ql_strcat.c
*/

#include "ql_string.h"

char *ql_strcat(char *dest, char const *src)
{
    int length = ql_strlen(dest);
    int idx = 0;

    for (; *src != '\0'; idx++)
        dest[idx + length] = *src++;
    return dest;
}

char *ql_strncat(char *dest, char const *src, int nb)
{
    int length = ql_strlen(dest);
    int idx = 0;

    for (; nb-- && *src != '\0'; idx++)
        dest[idx + length] = *src++;
    dest[idx + length] = '\0';
    return dest;
}
