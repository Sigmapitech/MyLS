/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** sort_entries.c
*/

#include "my_ls.h"
#include "quell/ql_debug.h"
#include "quell/ql_string.h"

static
void reorganize_elements(entry_t *cmp_l, entry_t *cmp_r)
{
    static entry_t swp;
    static char left[PATH_MAX + 1];
    static char right[NAME_MAX + 1];

    ql_strcpy(left, cmp_l->name);
    ql_strupcase(left);
    ql_strcpy(right, cmp_r->name);
    ql_strupcase(right);
    if (ql_strcmp(left, right) < 0) {
        swp = *cmp_r;
        *cmp_r = *cmp_l;
        *cmp_l = swp;
    }
}

void sort_entries(entry_t *entries, int count)
{
    for (int i = 0; i < count; i++)
        for (int j = 0; j < count; j++)
            reorganize_elements(entries + i, entries + j);
}
