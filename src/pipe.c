/*
** EPITECH PROJECT, 2024
** pipe
** File description:
** functions related to pipes
*/

#include <minishell2.h>

int count_pipes(char **tab)
{
    int count = 0;

    for (int i = 0; tab[i]; i++) {
        if (my_strcmp(tab[i], "|") == 0)
            count++;
    }
    return count;
}

int check_pipe(char **tab)
{
    for (int i = 0; tab[i]; i++) {
        if (my_strcmp(tab[i], "|") == 0)
            return 1;
    }
    return 0;
}

int pipe_position(char **tab)
{
    int pos = 0;

    while (tab[pos] != NULL)
        pos++;
    pos--;
    while (pos >= 0 && my_strcmp(tab[pos], "|") != 0) {
        pos--;
    }
    return pos;
}

static void execute_pipe(int fd[2], char **left_cmd, char **env, int *status)
{
    close(fd[1]);
    dup2(fd[0], STDIN_FILENO);
    close(fd[0]);
    if (check_builtin(left_cmd[0]) == 0)
        command(left_cmd[0], env, left_cmd);
    exit(1);
}

static int copy_command(char **left_cmd, char **right_cmd, char **tab)
{
    int j = 0;
    int pos = pipe_position(tab);

    if (pos - 1 < 0 || tab[pos + 1] == NULL) {
        my_putstr("Invalid null command.\n");
        return 1;
    }
    for (int i = 0; i != pos; i++) {
        left_cmd[j] = my_strdup(tab[i]);
        j++;
    }
    left_cmd[j] = NULL;
    j = 0;
    for (int i = pos + 1; tab[i]; i++) {
        right_cmd[j] = my_strdup(tab[i]);
        j++;
    }
    right_cmd[j] = NULL;
    return 0;
}

static void handle_right_child(int fd[2], char **left_cmd, char **env,
    int *status)
{
    pid_t pid = fork();

    if (pid == 0)
        execute_pipe(fd, left_cmd, env, status);
    close(fd[1]);
    close(fd[0]);
    waitpid(pid, status, 0);
}

static void close_file_descriptors(int fd[2])
{
    close(fd[0]);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);
}

static void handle_right_process(char **right_cmd, char **env, int *status,
    int fd[2])
{
    if (check_builtin(right_cmd[0]) == 1)
        check_command(right_cmd[0], env, right_cmd, status);
    else
        handle_right_child(fd, right_cmd, env, status);
}

static void execute_in_child(char **left_cmd, char **env, int *status)
{
    if (check_command(left_cmd[0], env, left_cmd, status) == 0)
        command(left_cmd[0], env, left_cmd);
}

void handle_pipe(char **tab, char **env, char *buffer, int *status)
{
    char **left_cmd = malloc(sizeof(char *) * (count_arguments(buffer) + 1));
    char **right_cmd = malloc(sizeof(char *) * (count_arguments(buffer) + 1));
    int fd[2];
    pid_t pid;

    if (copy_command(left_cmd, right_cmd, tab) == 1)
        return;
    pipe(fd);
    pid = fork();
    if (pid == 0) {
        close_file_descriptors(fd);
        if (count_pipes(tab) > 1)
            handle_pipe(left_cmd, env, buffer, status);
        if (!(count_pipes(tab) > 1))
            execute_in_child(left_cmd, env, status);
        exit(1);
    }
    handle_right_process(right_cmd, env, status, fd);
}
