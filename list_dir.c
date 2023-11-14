/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** list_dir.c
*/

#include <dirent.h>
#include <stddef.h>
#include <stdlib.h>

#include <sys/types.h>
#include <pwd.h>
#include <grp.h>

#include "quell/ql_base.h"
#include "quell/ql_debug.h"
#include "quell/ql_string.h"
#include "quell/ql_printf.h"

#include "my_ls.h"

static
void print_file_infos(entry_t *entry)
{
    ql_printf("%p %p %p ", entry->group, entry->passwd, entry->stat);
}

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
        if (flags & FLAG_L)
            print_file_infos(entry);
        ql_mprintf("%s", entry->name);
        ql_mprintf("%c", " \n"[(i + 1) == count || flags & FLAG_L]);
        entry += d;
    }
}

static
void get_file_info(char *dirname, entry_t *entry)
{
    static char path[PATH_MAX];
    int dirlen = ql_strlen(dirname);

    ql_strcpy(path, dirname);
    path[dirlen] = '/';
    ql_strcpy(&path[dirlen + 1], entry->name);
    if (stat(path, &entry->stat) < 0)
        return;
    entry->passwd = getpwuid(entry->stat.st_uid);
    entry->group = getgrgid(entry->stat.st_gid);
}

static
int read_directory(dirbuff_t *db, DIR *dir, char flags)
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
        if (flags & FLAG_L)
            get_file_info(db->name, &db->entries[i]);
        i++;
    }
    return i;
}

void list_dir(dirbuff_t *db, char flags)
{
    DIR *dir = opendir(db->name);
    int count;

    if (dir == NULL)
        return;
    count = read_directory(db, dir, flags);
    sort_entries(db->entries, count);
    print_entries(db->entries, count, flags);
    closedir(dir);
}
