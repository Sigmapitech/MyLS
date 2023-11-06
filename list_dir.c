/*
** EPITECH PROJECT, 2023
** __
** File description:
** _
*/

#include <dirent.h>
#include <stddef.h>
#include <stdlib.h>

#include "quell/ql_base.h"
#include "my_ls.h"
#include "quell/ql_string.h"

static
void free_leaves(char **leaves, int count)
{
    for (; --count;)
        free(leaves[count]);
}

static
int fill_up_leaves(DIR *dir, char **leaves)
{
    char **lp = leaves;
    struct dirent *dirent = readdir(dir);

    for (; dirent; dirent = readdir(dir)) {
        if (dirent->d_name[0] == '.')
            continue;
        *lp = ql_strdup(dirent->d_name);
        if (*lp == NULL) {
            free_leaves(leaves, lp - leaves);
            return -1;
        }
        lp++;
    }
    return lp - leaves;
}

void list_dir(char *dirpath)
{
    static char *leaves[1024];
    DIR *dir = opendir(dirpath);
    int count;

    if (dir == NULL)
        return;
    count = fill_up_leaves(dir, leaves);
    sort_entries(leaves, count);
    for (int i = 0; i < count; i++) {
        if (i)
            ql_mprintf("%s", " ");
        ql_mprintf("%s", leaves[i]);
    }
    ql_mprintf("\n");
    closedir(dir);
}
