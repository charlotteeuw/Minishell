/*
** EPITECH PROJECT, 2024
** my_tolower.c
** File description:
** converts str into lowercase
*/

#include <lib.h>

char *my_tolower(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
    return str;
}
