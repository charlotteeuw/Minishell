/*
** EPITECH PROJECT, 2023
** $MY_STRCMP
** File description:
** Function that compares two strings
*/

#include <lib.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0')
        i++;
    return (s1[i] - s2[i]);
}
