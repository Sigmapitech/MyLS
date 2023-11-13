/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** list_dir.c
*/

#include <dirent.h>
#include <stddef.h>
#include <stdlib.h>

#include "my_ls.h"
#include "quell/ql_base.h"
#include "quell/ql_debug.h"
#include "quell/ql_string.h"

static
int read_directory(DIR *dir, dirbuff_t *db)
{
    struct dirent *dirent = readdir(dir);
    size_t i = 0;

    for (; dirent; dirent = readdir(dir)) {
        if (dirent->d_name[0] == '.')
            continue;
        if (i == db->size) {
            db->size <<= 1;
            db->entries = ql_reallocarray(
                db->entries, i, db->size, sizeof(*db->entries));
        }
        ql_strcpy(db->entries[i].name, dirent->d_name);
        i++;
    }
    return i;
}

void list_dir(dirbuff_t *db, char *dirpath)
{
    DIR *dir = opendir(dirpath);
    int count;

    if (dir == NULL)
        return;
    count = read_directory(dir, db);
    sort_entries(db->entries, count);
    for (int i = 0; i < count; i++) {
        if (i)
            ql_mprintf("%s", " ");
        ql_mprintf("%s", db->entries[i].name);
    }
    ql_mprintf("\n");
    closedir(dir);
}
