/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** ql_strtok.c
*/

#include <stddef.h>
#include "ql_string.h"

char *ql_strtok_r(char *s, const char *delim, char **save_ptr)
{
    char *end;

    s = s ? s : *save_ptr;
    if (*s == '\0') {
        *save_ptr = s;
        return NULL;
    }
    s += ql_strspn(s, delim);
    if (*s == '\0') {
        *save_ptr = s;
        return NULL;
    }
    end = s + ql_strcspn(s, delim);
    if (*end == '\0') {
        *save_ptr = end;
        return s;
    }
    *end = '\0';
    *save_ptr = end + 1;
    return s;
}
