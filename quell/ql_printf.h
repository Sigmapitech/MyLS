/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** ql_printf.h
*/

#ifndef QL_PRINTF
    #define QL_PRINTF

    #include <stdarg.h>

int ql_printf(const char *format, ...);
int ql_dprintf(int fd, const char *format, ...);
int ql_vprintf(int fd, const char *format, va_list ap);
int ql_vdprintf(int fd, const char *format, va_list ap);

#endif
