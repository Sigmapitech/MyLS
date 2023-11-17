/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** recursion.c
*/

#include <stdlib.h>

#include "quell/ql_debug.h"
#include "quell/ql_string.h"

#include "my_ls.h"

char *path_concat(char *dest, char *basepath, char *suffix)
{
    int written = 0;

    ql_strcpy(dest, basepath);
    written = ql_strlen(basepath);
    if (dest[written - 1] != '/') {
        dest[written] = '/';
        written++;
    }
    ql_strcpy(dest + written, suffix);
    written += ql_strlen(suffix);
    dest[written] = '\0';
    return dest;
}

int recurse(dirbuff_t *db, int count, char flags)
{
    static char path[PATH_MAX];
    char **dirs = malloc(count * sizeof(char *));
    int dirsize = ql_strlen(db->name);
    int j = 0;

    for (int i = 0; i < count; i++) {
        if (S_ISDIR(db->entries[i].stat.st_mode)) {
            dirs[j] = ql_strdup(db->entries[i].name);
            j++;
        }
    }
    for (int i = 0; i < j; i++) {
        db->name = path_concat(path, db->name, dirs[i]);
        list_dir(db, flags);
        db->name[dirsize] = '\0';
    }
    free(dirs);
    return 0;
}
