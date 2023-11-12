/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** my_ls.h
*/

#ifndef MY_LS_H
    #define MY_LS_H

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

void list_dir(char *dirpath);
void sort_entries(entry_t *entries, int count);

#endif
