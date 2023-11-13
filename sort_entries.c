/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** sort_entries.c
*/

#include "my_ls.h"
#include "quell/ql_debug.h"
#include "quell/ql_string.h"

int compare_names(const void *left, const void *right)
{
    const char *sleft = ((entry_t *)left)->name;
    const char *sright = ((entry_t *)right)->name;

    for (; *sleft == '.'; sleft++);
    for (; *sright == '.'; sright++);
    for (; *sleft != '\0' && C_UP(*sleft) == C_UP(*sright);) {
        sleft++;
        sright++;
    }
    return C_UP(*sleft) - C_UP(*sright);
}

void sort_entries(entry_t *entries, int count)
{
    QL_DEBUG("len(entries): %d", count);
    ql_sort(entries, count, sizeof(*entries), &compare_names);
}
