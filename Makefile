##
## EPITECH PROJECT, 2023
## My LS
## File description:
## Makefile
##

.POSIX:
# .SUFFIXES: .d

CC := gcc
BUILD_DIR := .build

OUT := my_ls
OUT_DEBUG := debug

# ↓ `touch .fast` to force multi-threading
ifneq ($(shell find . -name ".fast"),)
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

LDFLAGS += -L $(BUILD_DIR) -lquell

VPATH += .
SRC += main.c
SRC += list_dir.c
SRC += print_info.c
SRC += sort_entries.c

vpath %.c $(VPATH)

OBJ := $(SRC:%.c=$(BUILD_DIR)/release/%.o)
OBJ_DEBUG := $(subst release,debug,$(OBJ))

DEP := $(OBJ:.o=.d)
DEP_DEBUG := $(OBJ_DEBUG:.o=.d)

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

all: $(OUT)
.PHONY: all

$(BUILD_DIR)/%/:
	@ mkdir -p $@

$(LIB):
	$(MAKE) -C quell

$(OUT_DEBUG): CFLAGS += -g3 -fsanitize=address,leak,undefined
$(OUT_DEBUG): CFLAGS += -DQL_DEBUG_MODE=1
$(OUT_DEBUG): $(BUILD_DIR)/debug/ .WAIT $(LIB) $(OBJ_DEBUG)
	$(CC) -o $@ $(CFLAGS) $(OBJ_DEBUG) $(LDFLAGS)
	@ $(LOG_TIME) $@

$(OUT): $(BUILD_DIR)/release/ .WAIT $(LIB) $(OBJ)
	$(CC) -o $@ $(CFLAGS) $(OBJ) $(LDFLAGS)
	@ $(LOG_TIME) $@

$(BUILD_DIR)/release/%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< || exit 1

$(BUILD_DIR)/debug/%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< || exit 1

clean:
	$(MAKE) -C quell clean
	$(RM) $(SRC:.c=.gcda)
	$(RM) $(SRC:.c=.gcno)
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) -C quell clean
	$(RM) -r $(BUILD_DIR)
	$(RM) $(OUT) $(OUT_DEBUG)

.PHONY: clean fclean

re: fclean .WAIT all
.PHONY: re

-include $(DEP)
-include $(DEP_DEBUG)
