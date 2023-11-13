/*
** EPITECH PROJECT, 2023
** __
** File description:
** _
*/

#include <stddef.h>
#include <stdlib.h>

#include "ql_base.h"

void *ql_realloc(void *ptr, size_t oldsize, size_t size)
{
    char *newp;

    if (size == 0)
        free(ptr);
    if (oldsize == 0)
        return NULL;
    newp = malloc(size);
    if (ptr == NULL || newp == NULL)
        return newp;
    ql_memcpy(newp, ptr, oldsize);
    free(ptr);
    return newp;
}

void *ql_reallocarray(void *ptr, size_t oldsize, size_t size, size_t elmsize)
{
    return ql_realloc(ptr, oldsize * elmsize, size * elmsize);
}
