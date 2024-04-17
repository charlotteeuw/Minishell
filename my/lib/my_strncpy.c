/*
** EPITECH PROJECT, 2024
** my_strncpy
** File description:
** my_strncpy
*/

#include <lib.h>

char *my_strncpy(char *dest, char *src, int n)
{
    int i = 0;

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
