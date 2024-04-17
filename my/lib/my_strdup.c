/*
** EPITECH PROJECT, 2023
** $MY_STRDUP
** File description:
** Duplicates a string and use malloc for memory
*/

#include <lib.h>

char *my_strdup(char const *src)
{
    int len1 = my_strlen(src);
    char *str;
    int i = 0;

    str = malloc(sizeof(char) * (len1 + 1));
    for (; src[i] != '\0'; i++)
        str[i] = src[i];
    str[i] = '\0';
    return str;
}
