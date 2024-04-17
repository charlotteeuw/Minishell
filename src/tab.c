/*
** EPITECH PROJECT, 2024
** tab
** File description:
** functions related to the array
*/

#include <minishell2.h>

static int count_nb_lines(char *buffer)
{
    int nb_lines = 1;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            nb_lines++;
    }
    return nb_lines;
}

static int count_nb_columns(char *buffer)
{
    int nb_columns = 0;

    for (int i = 0; buffer[i] != '\n' && buffer[i] != '\0'; i++) {
        nb_columns++;
    }
    return nb_columns;
}

int count_arguments(char *str)
{
    int counter = 0;
    int i = 0;

    while (str[i] != '\0') {
        while (str[i] == ' ' && str[i] != '\0') {
            i++;
        }
        while (str[i] != ' ' && str[i] != '\0') {
            i++;
        }
        counter++;
    }
    return counter;
}

int args_in_tab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL)
        i++;
    return i;
}

char **split_semicolons(char *buffer)
{
    int nb_arguments = count_arguments(buffer);
    char **arguments = malloc(sizeof(char *) * (nb_arguments + 1));
    char *token = strtok(buffer, ";");
    int i = 0;

    while (token != NULL) {
        arguments[i] = malloc(sizeof(char) * (my_strlen(token) + 1));
        my_strcpy(arguments[i], token);
        i++;
        token = strtok(NULL, ";");
    }
    arguments[i] = NULL;
    return arguments;
}

static void fill_tab(char **tab, char *buffer)
{
    char *token = strtok(buffer, " \t");
    int i = 0;

    while (token != NULL) {
        tab[i] = malloc(sizeof(char) * (my_strlen(token) + 1));
        my_strcpy(tab[i], token);
        i++;
        token = strtok(NULL, " \t");
    }
    tab[i] = NULL;
}

char **buffer_into_tab(char *buffer)
{
    int nb_arguments = count_arguments(buffer);
    char **tab = malloc(sizeof(char *) * (nb_arguments + 1));

    fill_tab(tab, buffer);
    return tab;
}
