/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** ql_memset.c
*/

#include "ql_base.h"

void *mem_set(void *src, byte_t c, size_t n)
{
    if (src == NULL)
        return NULL;
    for (byte_t *ptr = src; n--; *ptr++ = c)
        ;
    return src;
}
