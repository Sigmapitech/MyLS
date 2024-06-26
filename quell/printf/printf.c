/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** printf.c
*/

#include <stdarg.h>
#include <unistd.h>

#include "ql_printf.h"
#include "printf/internal.h"

int ql_dprintf(int fd, const char *format, ...)
{
    int written;
    va_list ap;

    if (format == NULL)
        return -1;
    va_start(ap, format);
    written = ql_vdprintf(fd, format, ap);
    va_end(ap);
    return written;
}

int ql_printf(const char *format, ...)
{
    int written;
    va_list ap;

    if (format == NULL)
        return -1;
    va_start(ap, format);
    written = ql_vdprintf(STDOUT_FILENO, format, ap);
    va_end(ap);
    return written;
}
