/*
** EPITECH PROJECT, 2024
** env
** File description:
** function related to the builtin env
*/

#include <minishell2.h>

int print_env(char *buffer, char **tab, char **env)
{
    int args = args_in_tab(tab);

    if (args > 1) {
        my_putstr("Too many arguments.\n");
        return 0;
    }
    for (int i = 0; env[i] != NULL; i++) {
        my_putstr(env[i]);
        my_putchar('\n');
    }
    return 0;
}
