/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** ql_strlen.c
*/

#include <stddef.h>
#include "ql_string.h"

int ql_strlen(char const *str)
{
    char const *p = str;

    for (; *p != '\0'; ++p)
        ;
    return p - str;
}

int ql_strnlen(char const *str, size_t n)
{
    char const *p = str;

    for (; n-- && *p != '\0'; ++p)
        ;
    return p - str;
}
