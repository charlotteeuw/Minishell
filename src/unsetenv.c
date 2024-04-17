/*
** EPITECH PROJECT, 2024
** unsetenv
** File description:
** function related to the builtin unsetenv
*/

#include <minishell2.h>

int my_unsetenv(char *buffer, char **tab, char **env)
{
    int index = 0;

    if (tab[1] == NULL) {
        write(2, "unsetenv: Too few arguments.\n",
        my_strlen("unsetenv: Too few arguments.\n"));
        return 1;
    }
    for (int i = 1; tab[i] != NULL; i++) {
        index = 0;
        if (env_exists(env, tab[i], &index) == 0)
            return 0;
        while (env[index] != NULL) {
            env[index] = env[index + 1];
            index++;
        }
    }
    return 0;
}
