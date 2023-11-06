/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** ql_debug.h
*/

#ifndef QL_DEBUG_H
    #define QL_DEBUG_H

    #include <stdio.h>
    #include "ql_base.h"

    #ifdef QL_DEBUG_MODE
        #define HEAD __FILE_NAME__, __LINE__

        #define HEAD_FMT_FILE BOLD BLUE "%s" RESET
        #define HEAD_FMT_LINE ":" BOLD PURPLE "%d" RESET

        #define HEAD_FMT HEAD_FMT_FILE HEAD_FMT_LINE "  "

        #define QL_DEBUG_MSG(msg) printf(HEAD_FMT "%s\n", HEAD, msg)
        #define QL_DEBUG(fmt, ...) printf(HEAD_FMT fmt "\n", HEAD, __VA_ARGS__)

        #define QL_DEBUG_CALL(func, ...) func(__VA_ARGS__)
    #else
        #define OMIT /* omitted */

        #define QL_DEBUG_MSG(msg) OMIT
        #define QL_DEBUG(fmt, ...) OMIT

        #define QL_DEBUG_CALL(func, ...) OMIT
    #endif

#endif
