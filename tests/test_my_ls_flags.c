/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** test_my_ls_flags.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_ls.h"

Test(my_ls, handle_l_lower_flag)
{
    char *av[] = {"./my_ls", "include", "-l"};
    int ac = sizeof(av) / sizeof(av[0]);
    flag_t flags;
    list_t *files;

    cr_redirect_stdout();
    get_flags(ac, av, &flags);
    cr_assert_eq(flags.list[L_LOWER], 1);
    files = get_files_and_folders(ac, av, flags);
    cr_assert_not_null(files);
    my_ls(files, flags);
    free_files_list(&files);
}

Test(my_ls, handle_r_lower_flag)
{
    char *av[] = {"./my_ls", "include", "-r"};
    int ac = sizeof(av) / sizeof(av[0]);
    flag_t flags;
    list_t *files;

    cr_redirect_stdout();
    get_flags(ac, av, &flags);
    cr_assert_eq(flags.list[R_LOWER], 1);
    files = get_files_and_folders(ac, av, flags);
    cr_assert_not_null(files);
    my_ls(files, flags);
    free_files_list(&files);
    cr_expect_stdout_eq_str("mylist.h\nmy_ls.h\nmy.h\n");
}

Test(my_ls, handle_t_lower_flag)
{
    char *av[] = {"./my_ls", "include", "-t"};
    int ac = sizeof(av) / sizeof(av[0]);
    flag_t flags;
    list_t *files;

    cr_redirect_stdout();
    get_flags(ac, av, &flags);
    cr_assert_eq(flags.list[T_LOWER], 1);
    files = get_files_and_folders(ac, av, flags);
    cr_assert_not_null(files);
    my_ls(files, flags);
    free_files_list(&files);
    cr_expect_stdout_eq_str("my.h\nmylist.h\nmy_ls.h\n");
}

Test(my_ls, handle_d_lower_flag)
{
    char *av[] = {"./my_ls", "include", "-d"};
    int ac = sizeof(av) / sizeof(av[0]);
    flag_t flags;
    list_t *files;

    cr_redirect_stdout();
    get_flags(ac, av, &flags);
    cr_assert_eq(flags.list[D_LOWER], 1);
    files = get_files_and_folders(ac, av, flags);
    cr_assert_not_null(files);
    my_ls(files, flags);
    free_files_list(&files);
    cr_expect_stdout_eq_str("include\n");
}

Test(my_ls, handle_r_upper_flag)
{
    char *av[] = {"./my_ls", "include", "-R"};
    int ac = sizeof(av) / sizeof(av[0]);
    flag_t flags;
    list_t *files;

    cr_redirect_stdout();
    get_flags(ac, av, &flags);
    cr_assert_eq(flags.list[R_UPPER], 1);
    files = get_files_and_folders(ac, av, flags);
    cr_assert_not_null(files);
    my_ls(files, flags);
    free_files_list(&files);
    cr_expect_stdout_eq_str("include:\nmy.h\nmy_ls.h\nmylist.h\n");
}
