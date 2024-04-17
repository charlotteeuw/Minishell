/*
** EPITECH PROJECT, 2024
** redirection.c
** File description:
** redirection
*/

#include <minishell2.h>

int check_redirection(char **tab)
{
    for (int i = 0; tab[i]; i++) {
        if (my_strcmp(tab[i], ">") == 0 || my_strcmp(tab[i], ">>") == 0 ||
            my_strcmp(tab[i], "<") == 0 || my_strcmp(tab[i], "<<") == 0)
            return 1;
    }
    return 0;
}

static int redirection_position(char **tab)
{
    int pos = 0;

    for (int i = 0; tab[i]; i++) {
        if (my_strcmp(tab[i], ">") == 0 || my_strcmp(tab[i], ">>") == 0 ||
            my_strcmp(tab[i], "<") == 0 || my_strcmp(tab[i], "<<") == 0)
            return i;
    }
    return pos;
}

static char **copy_cmd(char **tab, char *buffer)
{
    int pos = redirection_position(tab);
    char **cmd = malloc(sizeof(char *) * count_arguments(buffer) + 1);
    int j = 0;

    for (int i = 0; i != pos; i++) {
        cmd[j] = malloc(sizeof(char) * my_strlen(tab[i]) + 1);
        my_strcpy(cmd[j], tab[i]);
        j++;
    }
    cmd[j] = NULL;
    return cmd;
}

static char *find_keyword(char **tab, int i)
{
    char *word = NULL;

    if (my_strcmp(tab[i], "<<") == 0) {
        word = my_strdup(tab[i + 1]);
    }
    my_strcat(word, "\n");
    return word;
}

static char *copy_left_redirection(char **tab, int i)
{
    char *input_file = NULL;

    if (my_strcmp(tab[i], "<") == 0) {
        input_file = my_strdup(tab[i + 1]);
    }
    return input_file;
}

static char *copy_redirection(char **tab, int i)
{
    char *output_file = NULL;

    if (my_strcmp(tab[i], "<") != 0) {
        output_file = my_strdup(tab[i + 1]);
    }
    return output_file;
}

static void handle_right_redirections(char **tab, char **env, char *buffer,
    int i)
{
    char *output_file = NULL;
    char **cmd = copy_cmd(tab, buffer);
    int fd = 0;

    if (my_strcmp(tab[i], ">>") != 0 && my_strcmp(tab[i], ">") != 0)
        return;
    output_file = copy_redirection(tab, i);
    if (output_file != NULL) {
        if (my_strcmp(tab[i], ">>") == 0)
            fd = open(output_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
        else
            fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        dup2(fd, STDOUT_FILENO);
    }
}

static void handle_single_left(char *input_file, char **cmd, char **env,
    int fd)
{
    fd = open(input_file, O_RDONLY);
    if (fd == -1) {
        close(fd);
        my_putstr(input_file);
        my_putstr(": No such file or directory.\n");
        return;
    }
    dup2(fd, STDIN_FILENO);
}

static void handle_double_left(char **cmd, char **env, char **tab, int i)
{
    char *keyword = find_keyword(tab, i);
    long unsigned size = 0;
    char *buffer = "ABCDEFGHIJKLMNOP";
    int fd = open("tempfile", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    while (getline(&buffer, &size, stdin) != -1) {
        if (my_strcmp(buffer, keyword) == 0)
            break;
        write(fd, buffer, my_strlen(buffer));
    }
    free(buffer);
    close(fd);
    fd = open("tempfile", O_RDONLY, 0644);
    dup2(fd, STDIN_FILENO);
}

void handle_redirection(char **tab, char **env, char *buffer, int *status)
{
    char *input_file = NULL;
    char **cmd = copy_cmd(tab, buffer);
    int fd = 0;

    if (fork() != 0)
        return;
    for (int i = 0; tab[i]; i++) {
        if (my_strcmp(tab[i], "<") == 0) {
            input_file = copy_left_redirection(tab, i);
            handle_single_left(input_file, cmd, env, fd);
        }
        if (my_strcmp(tab[i], "<<") == 0)
            handle_double_left(cmd, env, tab, i);
        handle_right_redirections(tab, env, buffer, i);
    }
    execute_command(cmd[0], env, cmd);
    exit(1);
}
