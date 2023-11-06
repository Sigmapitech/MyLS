/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** ql_base.h
*/

#ifndef QL_BASE_H
    #define QL_BASE_H

    #include <stddef.h>

    #define MIN(x, y) (((x) > (y)) ? (x) : (y))
    #define ATTR(key) __attribute__((key))

    #define UNUSED ATTR(unused)

    #define CFMT(n) "\033[" #n "m"

    #define RESET CFMT(0)
    #define BOLD CFMT(1)

    #define RED CFMT(31)
    #define GREEN CFMT(32)
    #define YELLOW CFMT(33)
    #define BLUE CFMT(34)
    #define PURPLE CFMT(35)
    #define CYAN CFMT(36)

typedef unsigned char byte_t;
typedef unsigned int uint_t;
typedef unsigned long long ull_t;

int ql_getnbr(char *str);
int ql_getnbr_base(char *str, char const *base);
int ql_mprintf(const char *format, ...);
int ql_putnbr(int n);
int ql_putnbr_base(int nbr, char const *base);
int ql_putstr(char const *str);
int ql_showmem(char const *str, int size);
int ql_showstr(char const *str);
size_t ql_memlen(void *chunk, size_t csize);
void *ql_calloc(size_t nmemb, size_t size);
void *ql_memcpy(void *dest, const void *src, size_t n);
void *ql_memset(void *s, int c, size_t n);
void ql_putchar(char c);
void ql_puthex(int line, int pad);

#endif
