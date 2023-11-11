/*
** EPITECH PROJECT, 2023
** __
** File description:
** _
*/

#ifndef QL_PRINTF
    #define QL_PRINTF

    #include <stdarg.h>

int ql_printf(const char *format, ...);
int ql_dprintf(const char *format, ...);
int ql_vprintf(int fd, const char *format, va_list ap);
int ql_vdprintf(int fd, const char *format, va_list ap);

#endif
