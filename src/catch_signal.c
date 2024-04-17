/*
** EPITECH PROJECT, 2024
** catch_signal
** File description:
** functions related to catching signals
*/

#include <minishell2.h>

void check_exit_status(int status, int var)
{
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == 11 || WTERMSIG(status) == 6 ||
        WCOREDUMP(status)) {
            exit(128 + WTERMSIG(status));
        }
    }
    if (var == 0)
        exit(WEXITSTATUS(status));
    exit(status);
}

int handle_segv(int status)
{
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == 11 || WTERMSIG(status) == 6) {
            write(2, "Segmentation fault",
            my_strlen("Segmentation fault"));
        }
        if (WCOREDUMP(status)) {
            write(2, " (core dumped)",
            my_strlen(" (core dumped)"));
        }
        if ((WTERMSIG(status) == 11 || WTERMSIG(status) == 6)
            && WCOREDUMP(status))
            write(2, "\n", my_strlen("\n"));
    }
    return status;
}
