/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** my_ls.h
*/

#ifndef MY_LS_H
    #define MY_LS_H

    #include <stddef.h>

    #include <linux/limits.h>
    #include <sys/stat.h>

enum {
    EXIT_OK = 0,
    EXIT_KO = 84
};

typedef struct {
    struct stat stat;
    struct passwd *passwd;
    struct group *group;
    char name[NAME_MAX + 1];
} entry_t;

typedef struct {
    entry_t *entries;
    size_t size;
} dirbuff_t;

void list_dir(dirbuff_t *db, char *dirpath);
void sort_entries(entry_t *entries, int count);

#endif
