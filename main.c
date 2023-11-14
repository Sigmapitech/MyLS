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
    char flags = 0;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-' || argv[i][1] == '\0')
            continue;
        for (int j = 1; argv[i][j] != '\0'; j++)
            flags |= 1 << (ql_stridx(FLAGLIST, argv[i][j]) + 1);
    }
    return flags >> 1;
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
int list_dirs(int argc, char **argv, char flags)
{
    int err = 0;
    dirbuff_t db = {
        .size = 1024,
        .entries = malloc(1024 * sizeof(*db.entries)),
    };

    if (db.entries == NULL)
        return -1;
    if (count_targets(argc, argv) == 0) {
        db.name = DEFAULT_LOCATION;
        err |= list_dir(&db, flags);
    }
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-' && argv[i][1] != '\0')
            continue;
        db.name = argv[i];
        err |= list_dir(&db, flags);
    }
    free(db.entries);
    return err;
}

int main(int argc, char **argv)
{
    char flags = compose_flaglist(argc, argv);

    QL_DEBUG("Received %d parameters", argc);
    QL_DEBUG("Flag value: %x", flags);
    return (list_dirs(argc, argv, flags) < 0) ? EXIT_KO : EXIT_OK;
}
