/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** ql_mprintf.c
*/

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

#include "ql_base.h"
#include "ql_string.h"

static
size_t print_literal(const char *fmt, size_t *written)
{
    const char *s = fmt;

    for (; *fmt != '\0' && *fmt != '%'; fmt++);
    *written += fmt -s;
    return write(STDOUT_FILENO, s, fmt - s);
}

static
int handle_lookahead(const char *format, va_list *ap)
{
    char c;
    char *s;

    switch (format[1]) {
        case 'i':
        case 'd':
            return ql_putnbr(va_arg(*ap, int));
        case 's':
            s = va_arg(*ap, char *);
            return write(STDOUT_FILENO, s, ql_strlen(s));
        case 'c':
            c = va_arg(*ap, int);
            return write(STDOUT_FILENO, &c, sizeof(char));
        default:
            return write(
                STDOUT_FILENO,
                format,
                (1 + *format != '%') * sizeof(char)
            );
    }
}

int ql_mprintf(const char *format, ...)
{
    size_t written = 0;
    va_list args;

    va_start(args, format);
    while (*format != '\0') {
        if (*format != '%') {
            format += print_literal(format, &written);
            continue;
        }
        if (format[1] == '\0')
            return write(STDOUT_FILENO, format, sizeof(char));
        written += handle_lookahead(format, &args);
        format += 2;
    }
    va_end(args);
    return written;
}
