/*
** EPITECH PROJECT, 2023
** My LS
** File description:
** print_info.c
*/

#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <sys/types.h>
#include <time.h>

#include "quell/ql_base.h"
#include "quell/ql_debug.h"
#include "quell/ql_printf.h"
#include "quell/ql_string.h"

#include "my_ls.h"

static
void get_file_right(char bits[], entry_t *entry)
{
    mode_t mode = entry->stat.st_mode;
    static const char *s = "-rwx";

    bits[0] = s[(unsigned char)ZERO_OR(mode & S_IRUSR, 1)];
    bits[1] = s[(unsigned char)ZERO_OR(mode & S_IWUSR, 2)];
    bits[2] = s[(unsigned char)ZERO_OR(mode & S_IXUSR, 3)];
    bits[3] = s[(unsigned char)ZERO_OR(mode & S_IRGRP, 1)];
    bits[4] = s[(unsigned char)ZERO_OR(mode & S_IWGRP, 2)];
    bits[5] = s[(unsigned char)ZERO_OR(mode & S_IXGRP, 3)];
    bits[6] = s[(unsigned char)ZERO_OR(mode & S_IROTH, 1)];
    bits[7] = s[(unsigned char)ZERO_OR(mode & S_IWOTH, 2)];
    bits[8] = s[(unsigned char)ZERO_OR(mode & S_IXOTH, 3)];
    if (mode & S_ISUID)
        bits[1] = (mode & S_IXUSR) ? 's' : 'S';
    if (mode & S_ISGID)
        bits[3] = (mode & S_IXGRP) ? 's' : 'l';
    if (mode & S_ISVTX)
        bits[8] = (mode & S_IXOTH) ? 't' : 'T';
}

static
char get_file_type(entry_t *entry)
{
    const char typ[] = {
        [ S_IFBLK ] = 'b',
        [ S_IFCHR ] = 'c',
        [ S_IFDIR ] = 'd',
        [ S_IFIFO ] = 'p',
        [ S_IFLNK ] = 'l',
        [ S_IFREG ] = '-',
        [ S_IFSOCK ] = 's',
        [ 0 ] = '?'
    };

    return typ[(entry->stat.st_mode & S_IFMT)];
}

static
char *get_creation_time(entry_t *entry)
{
    static char fmt[12];
    char *ct = ctime(&entry->stat.st_mtim.tv_sec);
    time_t now = time(NULL);
    const int six_month_sec = 6 * 24 * 3600 * 31;

    if (entry->stat.st_mtim.tv_sec + six_month_sec < now) {
        ql_strncpy(fmt, ct + 4, 7);
        ql_strncpy(fmt + 7, ct + 19, 5);
    } else
        ql_strncpy(fmt, ct + 4, 12);
    return fmt;
}

static
void print_file_infos(entry_t *entry)
{
    struct stat *fi = &entry->stat;
    char perms[10] = { [0] = get_file_type(entry) };
    const char *owner = (entry->passwd == NULL) ? "?" : entry->passwd->pw_name;
    const char *grp = (entry->group == NULL) ? "?" : entry->group->gr_name;
    char *time = get_creation_time(entry);

    get_file_right(perms + 1, entry);
    ql_printf("%.10s %d %s %s ", perms, fi->st_nlink, owner, grp);
    if (ql_stridx("bc", perms[0]) != -1)
        ql_printf("%d, %d", major(fi->st_rdev), minor(fi->st_rdev));
    else
        ql_printf("%d", fi->st_size);
    ql_printf(" %.12s ", time);
}

void print_entries(entry_t *entry, int count, char flags)
{
    int d;

    if (flags & F_REV_ORDER) {
        d = -1;
        entry += (count - 1);
    } else
        d = 1;
    for (int i = 0; i < count; i++) {
        if (flags & F_LONG_FORM)
            print_file_infos(entry);
        ql_mprintf("%s", entry->name);
        ql_mprintf(((i + 1) == count || flags & F_LONG_FORM) ? "\n" : "  ");
        entry += d;
    }
}
