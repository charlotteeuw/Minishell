/*
** EPITECH PROJECT, 2024
** path
** File description:
** function related to finding paths
*/

#include <minishell2.h>

char *get_path(char **env)
{
    char *path;

    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "PATH=", 5) == 0) {
            path = my_strdup(env[i] + 5);
            break;
        }
    }
    return path;
}

char *get_home_path(char **env)
{
    char *path;

    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "HOME=", 5) == 0) {
            path = my_strdup(env[i] + 5);
            break;
        }
    }
    return path;
}

char *find_last_path(char **env)
{
    char *path;

    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "OLDPWD=", 7) == 0) {
            path = my_strdup(env[i] + 7);
            break;
        }
    }
    return path;
}
