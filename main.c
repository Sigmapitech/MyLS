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
    const char *flaglist = "alRdrt";
    char flags = 0;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-' || argv[i][1] == '\0')
            continue;
        for (int j = 1; argv[i][j] != '\0'; j++)
            flags |= 1 << (ql_stridx(flaglist, argv[i][j]) + 1);
    }
    return flags >> 1;
}

int main(int argc, char **argv)
{
    char flags = compose_flaglist(argc, argv);
    dirbuff_t db = {
        .size = 1024,
        .entries = malloc(1024 * sizeof(*db.entries)),
    };

    QL_DEBUG("Received %d parameters", argc);
    QL_DEBUG("Flag value: %x", flags);
    if (db.entries == NULL)
        return EXIT_KO;
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-' && argv[i][1] != '\0')
            continue;
        list_dir(&db, argv[i]);
    }
    free(db.entries);
    return EXIT_OK;
}
