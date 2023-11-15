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

enum {
    EXIT_OK = 0,
    EXIT_KO = 84
};

enum {
    FLAG_A = 1 << 1,
    FLAG_L = 1 << 2,
    FLAG_R_UP = 1 << 3,
    FLAG_D = 1 << 4,
    FLAG_R = 1 << 5,
    FLAG_T = 1 << 6,
    FLAG_SHOW_DIR = 1 << 7
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
    size_t size;
} dirbuff_t;

int list_dir(dirbuff_t *db, char flags);
void print_entries(entry_t *entry, int count, char flags);

void sort_entries(entry_t *entries, int count);
void sort_entries_by_time(entry_t *entries, int count);
#endif
