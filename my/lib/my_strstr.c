/*
** EPITECH PROJECT, 2024
** my_strstr.c
** File description:
** find a string in the first string
*/

#include <lib.h>

char *my_strstr(char *s1, char *s2)
{
    int j = 0;

    for (int i = 0; s1[i] != '\0'; i++) {
        j = 0;
        while (s1[i] == s2[j] && s1[i] != '\0' && s2[j] != '\0') {
            i++;
            j++;
        }
        if (s2[j] == '\0')
            return &s1[i];
    }
    return NULL;
}
