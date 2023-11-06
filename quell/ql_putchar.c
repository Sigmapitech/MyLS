/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** ql_putchar.c
*/

#include <unistd.h>
#include "ql_base.h"

void ql_putchar(char c)
{
    (void)write(STDOUT_FILENO, &c, sizeof(char));
}
