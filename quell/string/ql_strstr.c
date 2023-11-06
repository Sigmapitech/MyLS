/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** ql_strstr.c
*/

#include <stddef.h>
#include "ql_string.h"

char *ql_strstr(char *str, char const *to_find)
{
    int needle_size = ql_strlen(to_find);

    if (*to_find == '\0')
        return str;
    for (; *str != '\0'; str++)
        if (!ql_strncmp(str, to_find, needle_size))
            return str;
    return NULL;
}
