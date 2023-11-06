/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** ql_strrev.c
*/

#include "ql_string.h"

char *ql_strrev(char *str)
{
    unsigned int len = ql_strlen(str);
    unsigned int half = len >> 1;
    char swap;

    for (unsigned int i = 0; i < half; i++) {
        swap = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = swap;
    }
    return str;
}
