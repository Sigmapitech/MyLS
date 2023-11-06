/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** ql_memcpy.c
*/

#include <stddef.h>
#include "ql_base.h"

void *ql_memcpy(void *dest, const void *src, size_t n)
{
    byte_t const *srcp = src;

    if (dest == NULL || src == NULL)
        return NULL;
    for (byte_t *destp = dest; n--; *destp++ = *srcp++)
        ;
    return dest;
}
