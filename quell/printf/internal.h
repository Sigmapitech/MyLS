/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** internal.h
*/
#ifndef NO_USE_INTERNAL
    #define NO_USE_INTERNAL

    #include <stdarg.h>
    #include <stddef.h>
    #include <stdint.h>

    #define MAX_SPEC_LEN 2
    #define CONV_IDX(c) (c - 'A')

typedef enum {
    F_NO_FLAG = 0,
    F_PAD_LEFT = 1 << 0,
    F_PAD_ZERO = 1 << 1,
    F_ALT_FORM = 1 << 2,
    F_PUT_SIGN = 1 << 3,
    F_SET_SPACE = 1 << 4,
} flag_t;

typedef enum {
    CONV_NO = 0,
    CONV_CHAR = 1,
    CONV_SHORT = 2,
    CONV_LONG_LONG = 3,
    CONV_LONG = 4,
    CONV_INTMAX_T = 5,
    CONV_SIZE_T = 6,
    CONV_DOUBLE = 7,
    CONV_PTDRDIFF_T = 8
} len_mod_t;

typedef struct {
    char cmp[2];
    len_mod_t mod;
} len_mod_comp_t;

typedef struct {
    char *s;
    int written;
} small_buf_t;

typedef struct {
    size_t written;
    va_list ap;
    int fd;
    small_buf_t buf;
} print_info_t;

typedef struct {
    small_buf_t prefix;
    int width;
    int prec;
    char flag;
    char conv;
    len_mod_t len_mod;
} conv_info_t;

const char *parse_specifier(
    print_info_t *pinfo, conv_info_t *cinfo, const char *fmt);
const char *print_literal(print_info_t *pinfo, const char *fmt);
int print_format(print_info_t *pinfo, conv_info_t *cinfo, const char *fmt);

int double_to_str(char *out, double d, unsigned int prec);
int double_to_str_sci(char *out, double d, unsigned int prec);

int putnbr_str(char *s, intmax_t n);
int putnbr_base_str(char *s, size_t base, size_t n);
int base_len(int base, size_t n);

intmax_t pop_length_modifier(va_list *ap, len_mod_t lm);
uintmax_t pop_length_modifier_u(va_list *ap, len_mod_t lm);

static
const len_mod_comp_t LENGTH_MODIFIERS[8] = {
    { "hh", CONV_CHAR },
    { "h", CONV_SHORT },
    { "ll", CONV_LONG_LONG },
    { "l", CONV_LONG },
    { "j", CONV_INTMAX_T },
    { "z", CONV_SIZE_T },
    { "L", CONV_DOUBLE },
    { "t", CONV_PTDRDIFF_T }
};

#endif
