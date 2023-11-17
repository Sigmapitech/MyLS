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

static
char *path_concat(char *basepath, char *suffix)
{
    static char path[PATH_MAX];
    int written = 0;

    ql_strcpy(path, basepath);
    written = ql_strlen(basepath);
    if (path[written - 1] != '/') {
        path[written] = '/';
        written++;
    }
    ql_strcpy(path + written, suffix);
    written += ql_strlen(suffix);
    path[written] = '\0';
    return path;
}

int recurse(dirbuff_t *db, int count, char flags)
{
    int j = 0;
    char **dirs = malloc(count * sizeof(char *));
    int dirsize = ql_strlen(db->name);

    for (int i = 0; i < count; i++) {
        if (S_ISDIR(db->entries[i].stat.st_mode)) {
            dirs[j] = ql_strdup(db->entries[i].name);
            j++;
        }
    }
    for (int i = 0; i < j; i++) {
        db->name = path_concat(db->name, dirs[i]);
        list_dir(db, flags);
        db->name[dirsize] = '\0';
    }
    free(dirs);
    return 0;
}
