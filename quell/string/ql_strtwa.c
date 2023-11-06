/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** ql_strtwa.c
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "ql_string.h"

static
int count_words(char const *str)
{
    int count = 0;

    if (*str++ == '\0')
        return 0;
    for (; *str != '\0'; ++str)
        count += !IS_ALNUM(*str) && IS_ALNUM(*(str - 1));
    if (IS_ALNUM(*(str - 1)))
        count++;
    return count;
}

static
void remap_ptr(char **arr, char *str)
{
    char *p = str++;

    for (; *str != '\0'; ++str) {
        if (IS_ALNUM(*str) && !IS_ALNUM(*(str - 1)))
            p = str;
        if (!IS_ALNUM(*str) && IS_ALNUM(*(str - 1)))
            *arr++ = p;
        if (!IS_ALNUM(*str))
            *str = '\0';
    }
    if (IS_ALNUM(*(str - 1)))
        *arr++ = p;
    *arr = NULL;
}

char **ql_strtwa(char const *str)
{
    int count = count_words(str);
    char **out = malloc(
        (count + 1) * sizeof(char *) + (ql_strlen(str) + 1) * sizeof(char)
    );

    if (!count) {
        out[0] = NULL;
        return out;
    }
    if (out == NULL)
        return NULL;
    ql_strcpy((char *)&out[count + 1], str);
    remap_ptr(out, (char *)&out[count + 1]);
    return out;
}
