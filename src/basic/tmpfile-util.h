/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <fcntl.h>
#include <stdio.h>

int fopen_temporary_at(int dir_fd, const char *path, FILE **ret_file, char **ret_path);
static inline int fopen_temporary(const char *path, FILE **ret_file, char **ret_path) {
        return fopen_temporary_at(AT_FDCWD, path, ret_file, ret_path);
}
int mkostemp_safe(char *pattern);
int fmkostemp_safe(char *pattern, const char *mode, FILE**_f);

int tempfn_xxxxxx(const char *p, const char *extra, char **ret);
int tempfn_random(const char *p, const char *extra, char **ret);
int tempfn_random_child(const char *p, const char *extra, char **ret);

int open_tmpfile_unlinkable(const char *directory, int flags);
int open_tmpfile_linkable(const char *target, int flags, char **ret_path);
int fopen_tmpfile_linkable(const char *target, int flags, char **ret_path, FILE **ret_file);

int link_tmpfile(int fd, const char *path, const char *target);
int flink_tmpfile(FILE *f, const char *path, const char *target);

int mkdtemp_malloc(const char *template, char **ret);
int mkdtemp_open(const char *template, int flags, char **ret);
