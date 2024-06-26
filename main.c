/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** main.c
*/

#include <stdlib.h>

#include "quell/ql_debug.h"
#include "quell/ql_string.h"

#include "my_ls.h"

static
char compose_flaglist(int argc, char **argv)
{
    int flags = 0;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-' || argv[i][1] == '\0')
            continue;
        for (int j = 1; argv[i][j] != '\0'; j++)
        flags |= 1 << (ql_stridx(FLAGLIST, argv[i][j]) + 1);
    }
    return (char)(flags >> 1);
}

static
int count_targets(int argc, char **argv)
{
    int count = 0;

    for (int i = 1; i < argc; i++)
        if (argv[i][0] != '-' || argv[i][1] == '\0')
            count++;
    return count;
}

static
int list_dirs(dirbuff_t *db, int argc, char **argv, char flags)
{
    int err = 0;
    int count = count_targets(argc, argv);

    if (count == 0) {
        db->name = DEFAULT_LOCATION;
        err |= list_dir(db, flags);
    }
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-' && argv[i][1] != '\0')
            continue;
        db->name = argv[i];
        if (count > 1)
            flags |= F_SHOW_DIRS;
        err |= list_dir(db, flags);
    }
    return err;
}

int main(int argc, char **argv)
{
    dirbuff_t db = { .size = MIN_ALLOCATED_ENTRY };
    char flags = compose_flaglist(argc, argv);
    int err = 0;

    QL_DEBUG("Received %d parameters", argc);
    QL_DEBUG("Flag value: %x", flags);
    db.entries = malloc(db.size * sizeof(*db.entries));
    if (db.entries == NULL)
        return EXIT_KO;
    if (flags & F_DIRECTORY)
        flags &= ~F_RECURSIVE;
    err |= list_dirs(&db, argc, argv, flags);
    free(db.entries);
    return err ? EXIT_KO : EXIT_OK;
}
