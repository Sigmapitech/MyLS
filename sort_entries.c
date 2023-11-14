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
int compare_names(const void *left, const void *right)
{
    const char *sleft = ((entry_t *)left)->name;
    const char *sright = ((entry_t *)right)->name;
    const char *l = sleft;
    const char *r = sright;

    for (; *sleft == '.'; sleft++);
    for (; *sright == '.'; sright++);
    if (*sleft == '\0' && *sright == '\0')
        return (sleft - l) - (sright - r);
    for (; *sleft != '\0' && C_UP(*sleft) == C_UP(*sright);) {
        sleft++;
        sright++;
    }
    return C_UP(*sleft) - C_UP(*sright);
}

static
int compare_times(const void *left, const void *right)
{
    entry_t *lentry = (entry_t *)left;
    entry_t *rentry = (entry_t *)right;

    return (
        rentry->stat.st_mtim.tv_sec
        - lentry->stat.st_mtim.tv_sec
    );
}

void sort_entries(entry_t *entries, int count)
{
    QL_DEBUG("len(entries): %d", count);
    ql_sort(entries, count, sizeof(*entries), &compare_names);
}

void sort_entries_by_time(entry_t *entries, int count)
{
    ql_sort(entries, count, sizeof(*entries), &compare_times);
}
