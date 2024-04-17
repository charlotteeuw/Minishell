/*
** EPITECH PROJECT, 2024
** commands
** File description:
** functions related to the commands
*/

#include <minishell2.h>

void command(char *buffer, char **env, char **tab)
{
    char *command = get_command(buffer);
    char *error_message = malloc(sizeof(char) * (my_strlen(command) + 22));

    if (my_strcmp(command, "\0") == 0)
        exit(0);
    my_strcpy(error_message, command);
    my_strcat(error_message, ": Command not found.\n");
    check_executability(buffer, env, tab, error_message);
}

char *get_command(char *buffer)
{
    char *command = malloc(sizeof(char) * (my_strlen(buffer) + 1));
    int i = 0;

    for (i; buffer[i] != ' ' && buffer[i] != '\0'; i++)
        command[i] = buffer[i];
    command[i] = '\0';
    return command;
}

int check_command(char *buffer, char **env, char **tab, int *status)
{
    char *command = get_command(buffer);

    *status = -1;
    if (my_strcmp(command, "cd") == 0)
        (*status) = my_cd(tab, env);
    if (my_strcmp(command, "env") == 0)
        (*status) = print_env(buffer, tab, env);
    if (my_strcmp(command, "setenv") == 0)
        (*status) = my_setenv(buffer, tab, env);
    if (my_strcmp(command, "unsetenv") == 0)
        (*status) = my_unsetenv(buffer, tab, env);
    if (*status != -1)
        return 1;
    return 0;
}

int execute_command(char *buffer, char **env, char **tab)
{
    char *command = get_command(buffer);
    char *path = get_path(env);
    char *filepath = malloc(sizeof(char) * 1024);
    char *dir = strtok(path, ":");
    int status = access(tab[0], X_OK);

    my_strcpy(filepath, tab[0]);
    while (dir != NULL) {
        if (status != -1)
            break;
        my_strcpy(filepath, dir);
        my_strcat(filepath, "/");
        my_strcat(filepath, command);
        status = access(filepath, X_OK);
        dir = strtok(NULL, ":");
    }
    if (status != -1)
        execve(filepath, tab, env);
    free(filepath);
    return -1;
}
