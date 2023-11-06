/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** ql_strdup.c
*/

#include <stddef.h>
#include <stdlib.h>

#include "ql_string.h"

char *ql_strndup(char const *src, size_t n)
{
    char *out = malloc((n + 1) * sizeof(*out));

    if (out == NULL)
        return NULL;
    return ql_strncpy(out, src, n);
}

char *ql_strdup(char const *src)
{
    return ql_strndup(src, ql_strlen(src));
}
