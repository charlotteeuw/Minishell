/*
** EPITECH PROJECT, 2024
** set_new
** File description:
** function related to setting new variables
*/

#include <minishell2.h>

char *set_new_var(char *name, char *value)
{
    char *env_var;

    if (name == NULL)
        return NULL;
    env_var = malloc(sizeof(char) * my_strlen(name) +
    my_strlen(value) + 2);
    my_strcpy(env_var, name);
    my_strcat(env_var, "=");
    if (value != NULL)
        my_strcat(env_var, value);
    return env_var;
}

void set_new_env(char **env, char *env_var)
{
    int size = args_in_tab(env);
    char **new_env = malloc(sizeof(char *) * 1024);
    int i = 0;

    for (i; i < size; i++)
        new_env[i] = env[i];
    env[i] = env_var;
    env[i + 1] = NULL;
}
