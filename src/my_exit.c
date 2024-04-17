/*
** EPITECH PROJECT, 2024
** my_exit
** File description:
** function related to exitting the shell
*/

#include <minishell2.h>

void check_exit_command(char *buffer, char **tab, int status, char **env)
{
    if (my_strcmp(buffer, "exit") == 0)
        my_exit(tab, status, buffer, env);
}

int my_exit(char **tab, int status, char *buffer, char **env)
{
    char *error_message = "exit: Expression Syntax.\n";

    if (tab[1] != NULL && my_str_isnum(tab[1]) == 0) {
        write(2, error_message, my_strlen(error_message));
        return 1;
    }
    my_putstr("exit");
    my_putchar('\n');
    if (tab[1] != NULL && my_str_isnum(tab[1]) == 1)
        status = my_atoi(tab[1]);
    my_freetab(tab);
    free(buffer);
    my_freetab(env);
    exit(status);
}
