/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** ql_strtr.c
*/

#include "ql_string.h"

void ql_strtr(char *s, char search, char replace)
{
    for (char *p = s; *p != '\0'; ++p)
        if (*p == search)
            *p = replace;
}
