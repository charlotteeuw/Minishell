/*
** EPITECH PROJECT, 2024
** my_atoi
** File description:
** converts a string into an integer
*/

#include <lib.h>

int my_atoi(char *s)
{
    int i = 0;
    int number = 0;
    int sign = 1;

    while (s[i] == ' ')
        i++;
    if (s[i] == '-' && s[i] != '\0') {
        sign = -1;
        i++;
    }
    for (; '0' <= s[i] && s[i] <= '9'; i++) {
        number *= 10;
        number += s[i] - '0';
    }
    return sign * number;
}
