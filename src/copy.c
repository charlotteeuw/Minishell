/*
** EPITECH PROJECT, 2024
** copy
** File description:
** functions related to copying
*/

#include <minishell2.h>

int number_lines(char **env)
{
    int i = 0;

    while (env[i] != NULL)
        i++;
    return i;
}

char **copy_env(char **env)
{
    int size = number_lines(env);
    char **copy = malloc(sizeof(char *) * 1024);
    int i = 0;
    int j = 0;

    for (i = 0; i < size; i++) {
        copy[i] = malloc(sizeof(char) * my_strlen(env[i]) + 1);
        for (j = 0; env[i][j] != '\0'; j++)
            copy[i][j] = env[i][j];
        copy[i][j] = '\0';
    }
    copy[i] = NULL;
    return copy;
}
