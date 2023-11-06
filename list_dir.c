/*
** EPITECH PROJECT, 2023
** __
** File description:
** _
*/

#include <stddef.h>
#include <dirent.h>

#include "quell/ql_base.h"
#include "my_ls.h"

void list_dir(char *dirpath)
{
    DIR *dir = opendir(dirpath);
    struct dirent *dirent;
    int idx = 0;

    if (dir == NULL)
        return;
    dirent = readdir(dir);
    while (dirent != 0) {
        if (dirent->d_name[0] == '.') {
            dirent = readdir(dir);
            continue;
        }
        if (idx++)
            ql_mprintf("%s", " ");
        ql_mprintf("%s", dirent->d_name);
        dirent = readdir(dir);
    }
    ql_mprintf("\n");
    closedir(dir);
}
