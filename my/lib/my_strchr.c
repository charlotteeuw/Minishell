/*
** EPITECH PROJECT, 2024
** my_strchr.c
** File description:
** searches for the 1rst occurence of a character
*/

#include <lib.h>

char *my_strchr(char *str, int c)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return &str[i];
    }
    return NULL;
}
