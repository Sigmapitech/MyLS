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
#include "quell/ql_debug.h"
#include "quell/ql_string.h"
#include "quell/ql_printf.h"

#include "my_ls.h"

static
void print_entries(entry_t *entry, int count, char flags)
{
    int d;

    if (flags & FLAG_R) {
        d = -1;
        entry += (count - 1);
    } else
        d = 1;
    for (int i = 0; i < count; i++) {
        ql_printf("%s%c", entry->name, " \n"[(i + 1) == count]);
        entry += d;
    }
}

static
int read_directory(DIR *dir, dirbuff_t *db, char flags)
{
    struct dirent *dirent = readdir(dir);
    size_t i = 0;

    for (; dirent; dirent = readdir(dir)) {
        if (dirent->d_name[0] == '.' && ~flags & FLAG_A)
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

void list_dir(dirbuff_t *db, char *dirpath, char flags)
{
    DIR *dir = opendir(dirpath);
    int count;

    if (dir == NULL)
        return;
    count = read_directory(dir, db, flags);
    sort_entries(db->entries, count);
    print_entries(db->entries, count, flags);
    closedir(dir);
}
