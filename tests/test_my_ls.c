/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** test_my_ls.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_ls.h"

Test(my_ls, lists_directories_content)
{
    char *av[] = {"./my_ls", "include"};
    int ac = sizeof(av) / sizeof(av[0]);
    flag_t flags;
    list_t *files;

    cr_redirect_stdout();
    get_flags(ac, av, &flags);
    files = get_files_and_folders(ac, av, flags);
    cr_assert_not_null(files);
    my_ls(files, flags);
    free_files_list(&files);
    cr_expect_stdout_eq_str("my.h\nmy_ls.h\nmylist.h\n");
}

Test(my_ls, lists_files)
{
    char *av[] = {"./my_ls", "main.c", "Makefile"};
    int ac = sizeof(av) / sizeof(av[0]);
    flag_t flags;
    list_t *files;

    cr_redirect_stdout();
    get_flags(ac, av, &flags);
    files = get_files_and_folders(ac, av, flags);
    cr_assert_not_null(files);
    my_ls(files, flags);
    cr_expect_stdout_eq_str("Makefile\nmain.c\n");
    free_files_list(&files);
}

Test(my_ls, lists_files_and_directories_content)
{
    char *av[] = {"./my_ls", "include", "main.c"};
    int ac = sizeof(av) / sizeof(av[0]);
    flag_t flags;
    list_t *files;

    cr_redirect_stdout();
    get_flags(ac, av, &flags);
    files = get_files_and_folders(ac, av, flags);
    cr_assert_not_null(files);
    my_ls(files, flags);
    free_files_list(&files);
    cr_expect_stdout_eq_str("main.c\n\ninclude:\nmy.h\nmy_ls.h\nmylist.h\n");
}