/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** ql_string.h
*/

#ifndef QL_STRING_H
    #define QL_STRING_H

    #include <stddef.h>

    #define C_UP(c) ((c) | ' ')
    #define BOUNDS(c, lo, hi) (((c) >= (lo)) && ((c) <= (hi)))

    #define IS_LOWER(c) (BOUNDS(c, 'a', 'z'))
    #define IS_UPPER(c) (BOUNDS(c, 'A', 'Z'))
    #define IS_DIGIT(c) (BOUNDS(c, '0', '9'))
    #define IS_PRINT(c) (BOUNDS(c, ' ', '~'))

    #define IS_ALPHA(c) (IS_LOWER(C_UP(c)))
    #define IS_ALNUM(c) (IS_ALPHA(c) || IS_DIGIT(c))

char **ql_strtwa(char const *str);

char *ql_strcat(char *dest, char const *src);
char *ql_strchr(const char *s, char c);
char *ql_strcpy(char *dest, char const *src);
char *ql_strdup(char const *src);
char *ql_strlowcase(char *str);
char *ql_strncat(char *dest, char const *src, int nb);
char *ql_strncpy(char *dest, char const *src, int n);
char *ql_strndup(char const *src, size_t n);
char *ql_strrev(char *str);
char *ql_strstr(char *str, char const *to_find);
char *ql_strupcase(char *str);

int ql_strcmp(char const *s1, char const *s2);
int ql_stridx(const char *str, char c);
int ql_strlen(char const *str);
int ql_strncmp(char const *s1, char const *s2, int n);
int ql_strnlen(char const *str, size_t n);

size_t ql_strcspn(const char *s, const char *reject);
size_t ql_strspn(const char *s, const char *accept);

void ql_strtr(char *s, char search, char replace);
int ql_strpnum(char **strp);

#endif
