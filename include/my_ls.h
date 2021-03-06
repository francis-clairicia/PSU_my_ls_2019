/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** my_ls.h
*/

#ifndef HEADER_MY_LS
#define HEADER_MY_LS

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "my.h"
#include "mylist.h"

#define MAX(a, b) ((b > a) ? b : a)

#ifndef S_ISSOCK
#define S_ISSOCK(mode) __S_ISTYPE(mode, __S_IFSOCK)
#endif

#ifndef S_ISVTX
#define S_ISVTX	__S_ISVTX
#endif

enum FLAGS
{
    UNKNOWN_FLAG = -1,
    D_LOWER,
    L_LOWER,
    R_LOWER,
    R_UPPER,
    T_LOWER
};

enum TYPES
{
    ALL_TYPES = -1,
    FILE_TYPE,
    DIR_TYPE
};

enum SORTING_METHODS
{
    SORT_BY_ASCII,
    SORT_BY_MODIFICATIONS
};

struct flag_format
{
    char letter;
    int value;
};

typedef struct flag
{
    int nb;
    int *list;
} flag_t;

typedef struct file
{
    char *path;
    char *name;
    struct stat infos;
    enum TYPES type;
} file_t;

typedef struct padding
{
    int nlink;
    int user;
    int group;
    int maj_v;
    int min_v;
    int size;
} padding_t;

int my_ls(list_t *files, flag_t flags);

int get_flags(int ac, char **av, flag_t *flags);
list_t *get_files_and_folders(int ac, char **av, flag_t flags, int *output);
void free_files_list(list_t **files);
int get_file_infos(char *filepath, file_t *file);
void get_padding(list_t *files, padding_t *padding, int type);
int get_files_from_dir(list_t **list, DIR *dirp, char const *current_filepath);

void set_up_list(list_t *files, flag_t flags);
void sort_files(list_t *files, enum SORTING_METHODS method);
int sorted_by_ascii(file_t *first, file_t *second);
int sorted_by_modifications(file_t *first, file_t *second);

void print_file_path(file_t *file, flag_t flags, padding_t padding);
void print_file_name(file_t *file, flag_t flags, padding_t padding);
int print_dir_content(char const *filepath, flag_t flags, int print_filepath);
void print_long_format(file_t *file, char const *to_print,
    padding_t padding);
void print_infos(struct stat *infos, padding_t padding);
void print_number(long nb, int padding);
void print_permissions(mode_t mode);
void print_user(uid_t id, int padding);
void print_group(gid_t id, int padding);
void print_major_minor(dev_t dev_id, int padding_maj, int padding_min);
void print_time(time_t time);

int print_error_option(char flag);
int print_error_access(char const *filepath, char const *error);
int print_error_open(char const *filepath, char const *error);

char *join_path(char const *path_1, char const *path_2);

#endif