/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** my_ls.h
*/

#ifndef MY_LS_H
    #define MY_LS_H

    #include <stddef.h>

    #define ZERO_OR(expr, default) ((!!(expr)) * default)

    #include <linux/limits.h>
    #include <sys/stat.h>

    #define MIN_ALLOCATED_ENTRY (1024)

enum {
    EXIT_OK = 0,
    EXIT_KO = 84
};

enum {
    F_ALL_FILES = 1 << 0,
    F_LONG_FORM = 1 << 1,
    F_RECURSIVE = 1 << 2,
    F_DIRECTORY = 1 << 3,
    F_REV_ORDER = 1 << 4,
    F_SORT_TIME = 1 << 5,
    F_SHOW_DIRS = 1 << 6,
};

__attribute__((used))
static const char *FLAGLIST = "alRdrt";

__attribute__((used))
static char DEFAULT_LOCATION[2] = ".";

typedef struct {
    struct stat stat;
    struct passwd *passwd;
    struct group *group;
    char name[NAME_MAX + 1];
} entry_t;

typedef struct {
    char *name;
    entry_t *entries;
    int size;
    int is_file;
} dirbuff_t;

int list_dir(dirbuff_t *db, char flags);
int recurse(dirbuff_t *db, int count, char flags);

void print_entries(entry_t *entry, int count, char flags);
char *path_concat(char *basepath, char *suffix);

void sort_entries(entry_t *entries, int count);
void sort_entries_by_time(entry_t *entries, int count);
#endif
