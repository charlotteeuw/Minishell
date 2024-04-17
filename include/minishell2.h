/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** Header file for minishell2
*/

#ifndef MINISHELL2_H
    #define MINISHELL2_H

    #include <lib.h>

    #include <sys/types.h>
    #include <sys/wait.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <dirent.h>
    #include <signal.h>
    #include <errno.h>

char **copy_env(char **env);
int number_lines(char **env);

int shell(char **env);

void exec_cmd(int var, char *cmd, char **env, char **tab);
char *get_command(char *buffer);
int execute_command(char *buffer, char **env, char **tab);
int check_command(char *cmd, char **env, char **tab, int *status);
void command(char *buffer, char **env, char **tab);

char **split_semicolons(char *buffer);
char **buffer_into_tab(char *buffer);
int count_arguments(char *buffer);
int args_in_tab(char **tab);

int my_cd(char **tab, char **env);

char *get_path(char **env);
char *get_home_path(char **env);
char *find_last_path(char **env);

int print_env(char *buffer, char **tab, char **env);

int my_setenv(char *buffer, char **tab, char **env);
int env_exists(char **env, char *name, int *index);
void setenv_builtin(char *name, char *value, char **env);
int check_builtin(char *buffer);

char *set_new_var(char *name, char *value);
void set_new_env(char **env, char *env_var);

int my_unsetenv(char *buffer, char **tab, char **env);

int my_exit(char **tab, int status, char *buffer, char **env);
void check_exit_command(char *buffer, char **tab, int status, char **env);

int handle_segv(int signum);
void check_exit_status(int status, int var);

void clean_buffer(char *buffer);

int error_checking_setenv(char **tab);
int cd_error_checking(char **tab);
void check_executability(char *buffer, char **env, char **tab, char *error);

int check_pipe(char **tab);
void handle_pipe(char **tab, char **env, char *buffer, int *status);
int pipe_position(char **tab);
int count_pipes(char **tab);

void handle_redirection(char **tab, char **env, char *buffer, int *status);
int check_redirection(char **tab);

#endif /* MINISHELL2_H */
