/*
** EPITECH PROJECT, 2024
** setenv
** File description:
** function related to the builtin setenv
*/

#include <minishell2.h>

int env_exists(char **env, char *name, int *index)
{
    int len = my_strlen(name);
    int exists = 0;

    for (*index; env[*index] != NULL; (*index)++) {
        if (my_strncmp(name, env[*index], len) == 0) {
            exists = 1;
            return exists;
        }
    }
    return exists;
}

void setenv_builtin(char *name, char *value, char **env)
{
    int index = 0;
    char *env_var;

    if (env_exists(env, name, &index) == 1) {
        env[index] = set_new_var(name, value);
    } else {
        env_var = set_new_var(name, value);
        set_new_env(env, env_var);
    }
}

int my_setenv(char *buffer, char **tab, char **env)
{
    char *name = tab[1];
    char *value = NULL;
    int index = 0;

    if (tab[1] == NULL) {
        print_env(buffer, tab, env);
        return 0;
    }
    if (tab[1] != NULL && error_checking_setenv(tab) == 1)
        return 1;
    if (tab[2] != NULL)
        value = tab[2];
    setenv_builtin(name, value, env);
    return 0;
}
