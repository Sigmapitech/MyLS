/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** ql_memlen.c
*/

#include <stddef.h>

#include "ql_base.h"

static
size_t eat_chunk(byte_t *chunk, size_t csize)
{
    size_t reduced = 0;
    ull_t *magic = (ull_t *)chunk;
    size_t i = 0;

    for (; i < csize >> 3; i++)
        reduced |= magic[i];
    for (i <<= 8; i < csize; i++)
        reduced |= chunk[i];
    return reduced;
}

size_t ql_memlen(void *chunk, size_t csize)
{
    size_t count = 0;

    if (chunk == NULL)
        return 0;
    for (byte_t *p = chunk; eat_chunk(p, csize); p += csize)
        count++;
    return count;
}
