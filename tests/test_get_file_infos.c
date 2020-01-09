/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** test_get_file_infos.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_ls.h"

Test(get_file_infos, get_the_file_informations)
{
    file_t file;
    char filepath[] = "include/my.h";
    struct stat infos;

    cr_expect_eq(get_file_infos(filepath, &file), 1);
    stat(filepath, &infos);
    cr_expect_str_eq(file.path, filepath);
    cr_expect_str_eq(file.name, "my.h");
    cr_expect_eq(file.infos.st_ino, infos.st_ino);
    cr_expect_eq(file.type, FILE_TYPE);
}

Test(get_file_infos, get_the_dir_informations)
{
    file_t file;
    char filepath[] = "include/";
    struct stat infos;

    cr_expect_eq(get_file_infos(filepath, &file), 1);
    stat(filepath, &infos);
    cr_expect_str_eq(file.path, filepath);
    cr_expect_str_eq(file.name, "include/");
    cr_expect_eq(file.infos.st_ino, infos.st_ino);
    cr_expect_eq(file.type, DIR_TYPE);
}

Test(get_file_infos, handle_non_existing_file)
{
    file_t file;

    cr_redirect_stderr();
    cr_expect_eq(get_file_infos("unknown_file", &file), 0);
    cr_expect_stderr_eq_str("./my_ls: cannot access 'unknown_file': "
    "No such file or directory\n");
}