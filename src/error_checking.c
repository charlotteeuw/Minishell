/*
** EPITECH PROJECT, 2024
** error_checking
** File description:
** function related to checking errors
*/

#include <minishell2.h>

int error_checking_setenv(char **tab)
{
    char *error_message = "setenv: Variable must begin with a letter.\n";
    char *alphanum;

    alphanum = "setenv: Variable name must contain alphanumeric characters.\n";
    if (my_char_isalpha(tab[1][0]) == 0) {
        write(2, error_message, my_strlen(error_message));
        return 1;
    }
    if (tab[1] != NULL && my_str_isalpha(tab[1]) == 0) {
        write(2, alphanum, my_strlen(alphanum));
        return 1;
    }
    if (tab[2] != NULL && tab[3] != NULL) {
        write(2, "setenv: Too many arguments.\n",
        my_strlen("setenv: Too many arguments.\n"));
        return 1;
    }
    return 0;
}

int cd_error_checking(char **tab)
{
    char *error = "cd: Too many arguments.\n";
    struct stat file_type;

    if (tab[2] != NULL) {
        write(2, error, my_strlen(error));
        return 1;
    }
    if (stat(tab[1], &file_type) == -1) {
        write(2, tab[1], my_strlen(tab[1]));
        write(2, ": No such file or directory.\n",
        my_strlen(": No such file or directory.\n"));
        return 1;
    }
    if ((file_type.st_mode & __S_IFMT) != __S_IFDIR) {
        write(2, tab[1], my_strlen(tab[1]));
        write(2, ": Not a directory.\n", my_strlen(": Not a directory.\n"));
        return 1;
    }
    return 0;
}

void check_executability(char *buffer, char **env, char **tab, char *error)
{
    struct stat file_type = {0};

    stat(tab[0], &file_type);
    if (execute_command(buffer, env, tab) == -1) {
        if ((file_type.st_mode & __S_IFMT) == __S_IFDIR) {
            write(2, tab[0], my_strlen(tab[0]));
            write(2, ": Permission denied.\n",
            my_strlen(": Permission denied.\n"));
            exit(1);
        }
        if (errno == ENOEXEC) {
            write(2, tab[0], my_strlen(tab[0]));
            write(2, ": Exec format error. Wrong Architecture.\n",
            my_strlen(": Exec format error. Wrong Architecture.\n"));
            exit(1);
        }
        write(2, error, my_strlen(error));
        exit(1);
    }
}
