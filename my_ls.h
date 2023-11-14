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
    FLAG_A = 0x01,
    FLAG_L = 0x02,
    FLAG_R_UP = 0x04,
    FLAG_D = 0x08,
    FLAG_R = 0x10,
    FLAG_T = 0x20,
};

__attribute__((used))
static const char *FLAGLIST = "alRdrt";

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

void list_dir(dirbuff_t *db, char flags);
void print_entries(entry_t *entry, int count, char flags);

void sort_entries(entry_t *entries, int count);
void sort_entries_by_time(entry_t *entries, int count);
#endif
