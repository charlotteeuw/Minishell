/*
** EPITECH PROJECT, 2023
** $MY_STRCAT
** File description:
** Concatenates 2 strings
*/

#include <lib.h>

char *my_strcat(char *dest, char const *src)
{
    int len1 = my_strlen(dest);
    int len2 = my_strlen(src);

    for (int i = 0; i <= len2; i++) {
        dest[len1 + i] = src[i];
    }
    dest[len1 + len2] = '\0';
    return dest;
}
