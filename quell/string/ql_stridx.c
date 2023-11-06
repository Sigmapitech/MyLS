/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** ql_stridx.c
*/

#include "ql_string.h"

int ql_stridx(const char *str, char c)
{
    for (const char *p = str; *p != '\0'; p++)
        if (*p == c)
            return p - str;
    return -1;
}
