/*
** EPITECH PROJECT, 2023
** __
** File description:
** _
*/

#include "my_ls.h"
#include "quell/ql_string.h"

void sort_entries(char **entries, int count)
{
    char *swp;

    for (int i = 0; i < count; i++) {
        for (int j = 0;
            j < count
            && ql_strcmp(entries[i], entries[j]) < 0
        ; j++) {
            swp = entries[j];
            entries[j] = entries[i];
            entries[i] = swp;
        }
    }
}
