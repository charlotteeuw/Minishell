/*
** EPITECH PROJECT, 2024
** my_char_isnum
** File description:
** checks if a character is a number
*/

#include <lib.h>

int my_char_isnum(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

int my_char_isalpha(char c)
{
    if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
        return 1;
    return 0;
}

int my_str_isalpha(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_char_isalpha(str[i]) == 0 && my_char_isnum(str[i]) == 0)
            return 0;
    }
    return 1;
}
