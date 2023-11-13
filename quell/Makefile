##
## EPITECH PROJECT, 2023
## My LS
## File description:
## Makefile
##

.POSIX:
.SUFFIXES:

/ := ../
BUILD_DIR := $/.build

# ↓ `touch .fast` to force multi-threading
ifneq ($(shell find $/ -name ".fast"),)
    MAKEFLAGS += -j
endif

CC := gcc -std=c99

CFLAGS := -MMD -MP
CFLAGS += -fno-builtin
CFLAGS += -fno-tree-loop-distribute-patterns
CFLAGS += -pipe

CFLAGS += -U_FORTIFY_SOURCE -Wformat=2
CFLAGS += -O2 -march=native -mtune=native

CFLAGS += -Waggregate-return
CFLAGS += -Wall -Wextra -pedantic
CFLAGS += -Winit-self -Wredundant-decls
CFLAGS += -Winline -Wundef -Wshadow
CFLAGS += -Wunreachable-code
CFLAGS += -Wwrite-strings
CFLAGS += -iquote .

VPATH += .
SRC += ql_malloc.c
SRC += ql_memcpy.c
SRC += ql_memlen.c
SRC += ql_memset.c
SRC += ql_mprintf.c
SRC += ql_pow.c
SRC += ql_putchar.c
SRC += ql_putnbr.c
SRC += ql_putnbr_base.c
SRC += ql_putstr.c
SRC += ql_realloc.c
SRC += ql_showmem.c
SRC += ql_showstr.c

VPATH += string
SRC += ql_strcase.c
SRC += ql_strcat.c
SRC += ql_strcmp.c
SRC += ql_strcpy.c
SRC += ql_strdup.c
SRC += ql_stridx.c
SRC += ql_strlen.c
SRC += ql_strpnum.c
SRC += ql_strrev.c
SRC += ql_strspn.c
SRC += ql_strstr.c
SRC += ql_strtok.c
SRC += ql_strtr.c
SRC += ql_strtwa.c

VPATH += printf
SRC += vdprintf.c
SRC += parse_specifier.c
SRC += pop_length_mod.c
SRC += printf.c
SRC += putnbr_str.c

VPATH += printf/handlers
SRC += conversion_base.c
SRC += conversion_float.c
SRC += conversion_numerical.c

VPATH += printf/float
SRC += double_to_str.c
SRC += stringify_helpers.c
SRC += split_parts.c

vpath %.c $(VPATH)

OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)
DEP := $(OBJ:.o=.d)

LIB := $(BUILD_DIR)/libquell.a

RM ?= rm -f
AR ?= ar

ifneq ($(shell command -v tput),)
    ifneq ($(shell tput colors),0)

C_RESET := \033[00m
C_BOLD := \e[1m
C_RED := \e[31m
C_GREEN := \e[32m
C_YELLOW := \e[33m
C_BLUE := \e[34m
C_PURPLE := \e[35m
C_CYAN := \e[36m

    endif
endif

NOW = $(shell date +%s%3N)
STIME := $(call NOW)

TIME_NS = $(shell expr $(call NOW) - $(STIME))
TIME_MS = $(shell expr $(call TIME_NS))
LOG_TIME = echo -e "[ $(C_BLUE)$(call TIME_MS)$(C_RESET) ]"

all: $(LIB)

.PHONY: all

$(BUILD_DIR):
	@ mkdir -p $@

$(LIB): $(BUILD_DIR) .WAIT $(OBJ)
	$(AR) rc $@ $(OBJ)
	@ $(LOG_TIME) $@

$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< || exit 1

clean:
	$(RM) $(SRC:.c=.gcda)
	$(RM) $(SRC:.c=.gcno)
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(LIB)

.PHONY: clean fclean

re: fclean .WAIT all
.PHONY: re

-include $(DEP)
