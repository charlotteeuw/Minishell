/*
** EPITECH PROJECT, 2024
** clean_buffer
** File description:
** functions related to cleaning the buffer
*/

#include <minishell2.h>

void skip_spaces(char *buffer, int *i, int *j, char *clean)
{
    while (buffer[*i] == ' ' || buffer[*i] == '\t' || buffer[*i] == '\n')
        (*i)++;
    if (buffer[*i] != '\0') {
        clean[*j] = ' ';
        (*j)++;
    }
}

void clean_buffer(char *buffer)
{
    char *clean = malloc(sizeof(char) * my_strlen(buffer) + 1);
    int i = 0;
    int j = 0;

    buffer[my_strlen(buffer)] = '\0';
    while (buffer[i] == ' ' || buffer[i] == '\t' || buffer[i] == '\n')
        i++;
    while (buffer[i] != '\0') {
        if (buffer[i] == ' ' || buffer[i] == '\t' || buffer[i] == '\n') {
            skip_spaces(buffer, &i, &j, clean);
        } else {
            clean[j] = buffer[i];
            j++;
            i++;
        }
    }
    clean[j] = '\0';
    my_strcpy(buffer, clean);
}
