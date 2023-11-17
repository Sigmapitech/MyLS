/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** list_dir.c
*/

#include <dirent.h>
#include <errno.h>
#include <grp.h>
#include <pwd.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "quell/ql_base.h"
#include "quell/ql_debug.h"
#include "quell/ql_printf.h"
#include "quell/ql_string.h"

#include "my_ls.h"

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
    int i = 0;

    for (; dirent; dirent = readdir(dir)) {
        if (dirent->d_name[0] == '.' && ~flags & F_ALL_FILES)
            continue;
        if (i == db->size) {
            db->size <<= 1;
            db->entries = ql_reallocarray(
                db->entries, i, db->size, sizeof(*db->entries));
        }
        ql_strcpy(db->entries[i].name, dirent->d_name);
        if (flags & (F_LONG_FORM | F_SORT_TIME | F_RECURSIVE))
            get_file_info(db->name, &db->entries[i]);
        i++;
    }
    return i;
}

static
void print_error(char *dirname)
{
    switch (errno) {
        case ENOENT:
            ql_dprintf(STDERR_FILENO,
                "ls: cannot access '%s': No such file or directory\n",
                dirname);
            return;
        case EACCES:
            ql_dprintf(STDERR_FILENO,
                "ls: cannot open directory '%s': Permission denied\n",
                dirname);
            return;
        default:
            ql_dprintf(STDERR_FILENO, "Unknown error\n");
    }
}

static
int read_arg(dirbuff_t *db, char flags)
{
    struct stat fi;
    int count;
    DIR *dir;

    if (stat(db->name, &fi) < 0) {
        print_error(db->name);
        return -1;
    }
    if (S_ISDIR(fi.st_mode)) {
        dir = opendir(db->name);
        count = read_directory(db, dir, flags);
        closedir(dir);
        return count;
    }
    ql_strcpy(db->entries[0].name, db->name);
    db->entries[0].stat = fi;
    db->entries[0].passwd = getpwuid(db->entries[0].stat.st_uid);
    db->entries[0].group = getgrgid(db->entries[0].stat.st_gid);
    return 1;
}

int list_dir(dirbuff_t *db, char flags)
{
    int count = read_arg(db, flags);

    sort_entries(db->entries, count);
    if (flags & F_SORT_TIME)
        sort_entries_by_time(db->entries, count);
    if (flags & (F_SHOW_DIRS | F_RECURSIVE))
        ql_mprintf("%s:\n\n", db->name);
    print_entries(db->entries, count, flags);
    if (flags & F_RECURSIVE)
        recurse(db, count, flags);
    return 0;
}
