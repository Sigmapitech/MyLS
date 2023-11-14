/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** ql_sort.c
*/

#include "ql_base.h"

#include <stddef.h>
#include <stdint.h>

static
void swap(void *left, void *right, size_t size)
{
    uint8_t *l8 = left;
    uint8_t *r8 = right;

    for (uint8_t swp8; size; size--) {
        swp8 = *l8;
        *l8 = *r8;
        *r8 = swp8;
        l8++;
        r8++;
    }
}

void ql_sort(
    void *base, size_t nmemb, size_t size,
    int (*compar)(const void *, const void *))
{
    uint8_t *b = base;
    void *pivot = &b[(nmemb - 1) * size];
    int i = 0;

    if (nmemb <= 1)
        return;
    for (size_t j = 0; j < nmemb; j++) {
        if (compar(&b[j * size], pivot) < 0) {
            swap(&b[i * size], &b[j * size], size);
            i++;
        }
    }
    swap(&b[i * size], pivot, size);
    ql_sort(b, i, size, compar);
    ql_sort(&b[(i + 1) * size], nmemb - (i + 1), size, compar);
}
