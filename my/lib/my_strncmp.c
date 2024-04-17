/*
** EPITECH PROJECT, 2023
** $MY_STRNCMP
** File description:
** Compares the first n bytes of str1 and str2
*/

#include <lib.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i])
            return (s1[i] > s2[i] ? 1 : -1);
        if (s1[i] == '\0')
            return 0;
    }
    return 0;
}
