/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** ql_putstr.c
*/

#include "ql_base.h"
#include "ql_string.h"

int ql_putstr(char const *str)
{
    while (*str != '\0')
        ql_putchar(*str++);
    return 0;
}
