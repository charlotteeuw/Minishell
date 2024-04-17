/*
** EPITECH PROJECT, 2024
** cd
** File description:
** functions related to cd
*/

#include <minishell2.h>

int my_cd(char **tab, char **env)
{
    char *dir = tab[1];
    char *path;

    if (tab[1] != NULL && opendir(dir) == NULL &&
    my_strcmp(dir, "~") && my_strcmp(dir, "-"))
        return cd_error_checking(tab);
    if (dir == NULL || my_strcmp(dir, "~") == 0) {
        path = get_home_path(env);
        setenv_builtin("OLDPWD", getcwd(NULL, 0), env);
        chdir(path);
    } else if (my_strcmp(dir, "-") == 0) {
        path = find_last_path(env);
        setenv_builtin("OLDPWD", getcwd(NULL, 0), env);
        chdir(path);
    } else {
        setenv_builtin("OLDPWD", getcwd(NULL, 0), env);
        chdir(dir);
    }
    return 0;
}
