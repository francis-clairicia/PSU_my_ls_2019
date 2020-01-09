/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** test_get_files.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_ls.h"

Test(get_files_and_folders, get_the_files_to_read)
{
    flag_t flags;
    int ac = 3;
    char *av[] = {"./my_ls", "main.c", "-l"};
    int output = 0;
    list_t *files;
    file_t *file;

    get_flags(ac, av, &flags);
    files = get_files_and_folders(ac, av, flags, &output);
    cr_assert_not_null(files);
    cr_expect_eq(output, 0);
    file = (file_t *)(files->data);
    cr_expect_str_eq(file->path, "main.c");
    cr_expect_str_eq(file->name, "main.c");
    cr_expect_eq(file->type, FILE_TYPE);
    cr_expect_null(files->next);
    free_files_list(&files);
    free(flags.list);
}

Test(get_files_and_folders, handle_no_files)
{
    flag_t flags;
    int ac = 1;
    char *av[] = {"./my_ls"};
    int output = 0;
    list_t *files;
    file_t *file;

    get_flags(ac, av, &flags);
    files = get_files_and_folders(ac, av, flags, &output);
    cr_assert_not_null(files);
    cr_expect_eq(output, 0);
    file = (file_t *)(files->data);
    cr_expect_str_eq(file->path, ".");
    cr_expect_eq(file->type, DIR_TYPE);
    cr_expect_null(files->next);
    free_files_list(&files);
    free(flags.list);
}

Test(get_files_and_folders, handle_unknown_files)
{
    flag_t flags;
    int ac = 4;
    char *av[] = {"./my_ls", "unknown", "-t", "-r"};
    list_t *files;
    int output = 0;
    char error_msg[] = "./my_ls: cannot access 'unknown': "
        "No such file or directory\n";

    cr_redirect_stderr();
    get_flags(ac, av, &flags);
    files = get_files_and_folders(ac, av, flags, &output);
    cr_expect_null(files);
    cr_expect_eq(output, 84);
    cr_expect_stderr_eq_str(error_msg);
}