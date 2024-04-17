/*
** EPITECH PROJECT, 2024
** main
** File description:
** main function
*/

#include <minishell2.h>

int main(int argc, char **argv, char **env)
{
    char **copy = copy_env(env);

    if (argc != 1)
        return 84;
    return shell(copy);
    my_freetab(copy);
}
