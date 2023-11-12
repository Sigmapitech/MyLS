/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** list_dir.c
*/

#include <dirent.h>
#include <stddef.h>
#include <stdlib.h>

#include "quell/ql_base.h"
#include "my_ls.h"
#include "quell/ql_string.h"

static
int fill_up_leaves(DIR *dir, entry_t *entries)
{
    entry_t *p = entries;
    struct dirent *dirent = readdir(dir);

    for (; dirent; dirent = readdir(dir)) {
        if (dirent->d_name[0] == '.')
            continue;
        ql_strcpy(entries->name, dirent->d_name);
        entries++;
    }
    return entries - p;
}

void list_dir(char *dirpath)
{
    static entry_t entries[1024];
    DIR *dir = opendir(dirpath);
    int count;

    if (dir == NULL)
        return;
    count = fill_up_leaves(dir, entries);
    sort_entries(entries, count);
    for (int i = 0; i < count; i++) {
        if (i)
            ql_mprintf("%s", " ");
        ql_mprintf("%s", entries[i].name);
    }
    ql_mprintf("\n");
    closedir(dir);
}
