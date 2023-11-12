/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** sort_entries.c
*/

#include "my_ls.h"
#include "quell/ql_debug.h"
#include "quell/ql_string.h"

inline
void build_comp_str(char *restrict out, char *restrict s)
{
    for (; *s == '.'; s++);
    ql_strcpy(out, s);
    ql_strupcase(out);
}

static
void reorganize_elements(entry_t *cmp_l, entry_t *cmp_r)
{
    static entry_t swp;
    static char left[NAME_MAX + 1];
    static char right[NAME_MAX + 1];
    static entry_t *p = NULL;

    build_comp_str(right, cmp_r->name);
    if (p != cmp_l) {
        build_comp_str(left, cmp_l->name);
        p = cmp_l;
    }
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
