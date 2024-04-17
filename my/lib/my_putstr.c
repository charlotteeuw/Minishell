/*
** EPITECH PROJECT, 2023
** $MY_PUTSTR
** File description:
** Displays one by one the characters of a string
*/

#include <lib.h>

int my_putstr(char const *str)
{
    int len = my_strlen(str);

    return write(1, str, len);
}
