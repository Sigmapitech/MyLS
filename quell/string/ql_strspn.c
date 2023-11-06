/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** ql_strspn.c
*/

#include <stddef.h>
#include "ql_string.h"

char *ql_strchr(const char *s, char c)
{
    for (char *p = (char *)s; *p != '\0'; p++)
        if (*p == c)
            return p;
    return NULL;
}

size_t ql_strspn(const char *s, const char *accept)
{
    const char *p = s;

    for (; *p != '\0' && ql_strchr(accept, *p) != NULL; p++)
        ;
    return p - s;
}

size_t ql_strcspn(const char *s, const char *reject)
{
    const char *p = s;

    for (; *p != '\0' && ql_strchr(reject, *p) == NULL; p++)
        ;
    return p - s;
}
