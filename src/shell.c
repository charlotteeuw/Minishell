/*
** EPITECH PROJECT, 2024
** shell
** File description:
** functions related to the shell itself
*/

#include <minishell2.h>

int check_builtin(char *buffer)
{
    char *command = get_command(buffer);

    if (my_strcmp(command, "cd") == 0)
        return 1;
    if (my_strcmp(command, "env") == 0)
        return 1;
    if (my_strcmp(command, "setenv") == 0)
        return 1;
    if (my_strcmp(command, "unsetenv") == 0)
        return 1;
    return 0;
}

void check_if_isatty(void)
{
    if (isatty(0) == 1)
        my_putstr("$> ");
}

void end_of_shell(int status, char **buffer, char **tab)
{
    handle_segv(status);
    my_freetab(tab);
}

void exec_cmd(int var, char *cmd, char **env, char **tab)
{
    if (var == 0 && fork() == 0)
        command(cmd, env, tab);
}

static int syntax_error(char **tab)
{
    if (tab[0][0] == '|' || tab[0][my_strlen(tab[0]) - 1] == '|') {
        my_putstr("Invalid null command.\n");
        return 1;
    }
    return 0;
}

static void parse_commands(char **commands, int status, char **env,
    char *buffer)
{
    char **tab = NULL;
    int var = 0;
    int pos = 0;

    for (int i = 0; commands[i] != NULL; i++) {
        clean_buffer(commands[i]);
        tab = buffer_into_tab(commands[i]);
        check_exit_command(commands[i], tab, status, env);
        if (check_pipe(tab) == 1)
            handle_pipe(tab, env, buffer, &status);
        if (check_redirection(tab) == 1)
            handle_redirection(tab, env, buffer, &status);
        if (check_pipe(tab) == 0 && check_redirection(tab) == 0) {
            var = check_command(commands[i], env, tab, &status);
            exec_cmd(var, commands[i], env, tab);
        }
        wait(&status);
        end_of_shell(status, &buffer, tab);
    }
}

int shell(char **env)
{
    long unsigned size = 0;
    char *buffer = NULL;
    char **tab;
    char **commands;
    int status = 0;
    int var = 0;
    int pipe = 0;

    while (1) {
        check_if_isatty();
        if (getline(&buffer, &size, stdin) == -1)
            check_exit_status(status, var);
        clean_buffer(buffer);
        commands = split_semicolons(buffer);
        parse_commands(commands, status, env, buffer);
        free(buffer);
        buffer = NULL;
        my_freetab(commands);
    }
    return status;
}
