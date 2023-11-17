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

static
int find_directories(char **dirs, dirbuff_t *db, int count)
{
    int found = 0;

    if (dirs == NULL)
        return -1;
    for (int i = 0; i < count; i++) {
        if (!ql_strcmp(db->entries[i].name, ".")
            || !ql_strcmp(db->entries[i].name, ".."))
            continue;
        if (S_ISDIR(db->entries[i].stat.st_mode)) {
            dirs[found] = ql_strdup(db->entries[i].name);
            found++;
        }
    }
    return found;
}

int recurse(dirbuff_t *db, int count, char flags)
{
    static char path[PATH_MAX];
    int dirsize = ql_strlen(db->name);
    char **dirs = malloc(count * sizeof(char *));
    int j = find_directories(dirs, db, count);

    if (j == -1)
        return -1;
    for (int i = 0; i < j; i++) {
        db->name = path_concat(path, db->name, dirs[i]);
        list_dir(db, flags);
        db->name[dirsize] = '\0';
    }
    free(dirs);
    return 0;
}
