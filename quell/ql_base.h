/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** ql_base.h
*/

#ifndef QL_BASE_H
    #define QL_BASE_H

    #include <stddef.h>
    #include <stdint.h>

    #define ABS(x) (((x) > 0) ? (x) : (-x))

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

int ql_pow(int nb, int p);
int ql_intlen(intmax_t i);

size_t ql_memlen(void *chunk, size_t csize);
void *ql_calloc(size_t nmemb, size_t size);
void *ql_memcpy(void *dest, const void *src, size_t n);
void *ql_memset(void *s, int c, size_t n);

void *ql_realloc(void *ptr, size_t oldsize, size_t size);
void *ql_reallocarray(void *ptr, size_t oldsize, size_t size, size_t elmsize);

typedef int (*cmpf_t)(const void *, const void *);
void ql_sort(void *base, size_t nmemb, size_t size, cmpf_t compar);

void ql_putchar(char c);
int ql_putnchar(int fd, char c, int nb);

void ql_puthex(int line, int pad);

#endif
