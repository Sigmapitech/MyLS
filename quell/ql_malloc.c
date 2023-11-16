/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** ql_malloc.c
*/

#include <stddef.h>
#include <stdlib.h>

#include "ql_base.h"

void *ql_calloc(size_t memb, size_t size)
{
    void *dest = malloc(memb * size);

    if (dest != NULL)
        ql_memset(dest, '\0', (memb * size));
    return dest;
}
