/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** ql_strcase.c
*/

#include "ql_string.h"

char *ql_strupcase(char *str)
{
    const char up_mask = ~(1 << 5);
    char *p = str;

    for (; *p != '\0'; p++)
        if (IS_LOWER(*p))
            *p &= up_mask;
    return str;
}

char *ql_strlowcase(char *str)
{
    char *p = str;

    for (; *p != '\0'; p++)
        if (IS_UPPER(*p))
            *p |= (1 << 5);
    return str;
}
