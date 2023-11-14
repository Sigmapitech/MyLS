/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** print_info.c
*/

#include <stddef.h>
#include <stdlib.h>

#include <dirent.h>
#include <pwd.h>
#include <grp.h>

#include <sys/types.h>
#include <sys/stat.h>

#include "quell/ql_base.h"
#include "quell/ql_debug.h"
#include "quell/ql_string.h"
#include "quell/ql_printf.h"

#include "my_ls.h"

static
void get_file_right(char *out, entry_t *entry)
{
    int mode = entry->stat.st_mode;
    const char *s = "-rwx";
    char buf[9] = {
        [0] = s[ZERO_OR(mode & S_IRUSR, 1)],
        [1] = s[ZERO_OR(mode & S_IWUSR, 2)],
        [2] = s[ZERO_OR(mode & S_IXUSR, 3)],
        [3] = s[ZERO_OR(mode & S_IRGRP, 1)],
        [4] = s[ZERO_OR(mode & S_IRGRP, 2)],
        [5] = s[ZERO_OR(mode & S_IWGRP, 3)],
        [6] = s[ZERO_OR(mode & S_IROTH, 1)],
        [7] = s[ZERO_OR(mode & S_IWOTH, 2)],
        [8] = s[ZERO_OR(mode & S_IXOTH, 3)],
    };

    ql_strncpy(out, buf, 9);
}

static
char get_file_type(entry_t *entry)
{
    const char typ[] = {
        [ S_IFBLK ] = 'b',
        [ S_IFCHR ] = 'c',
        [ S_IFDIR ] = 'd',
        [ S_IFIFO ] = 'p',
        [ S_IFLNK ] = 'l',
        [ S_IFREG ] = '-',
        [ S_IFSOCK ] = 's',
        [ 0 ] = '?'
    };

    return typ[(entry->stat.st_mode & S_IFMT)];
}

static
void print_file_infos(entry_t *entry)
{
    char perms[10] = {
        [0] = get_file_type(entry)
    };

    get_file_right(perms + 1, entry);
    ql_printf("%s %p %p ",
        perms,
        entry->group, entry->passwd, entry->stat);
}

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
