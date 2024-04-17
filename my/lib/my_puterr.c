/*
** EPITECH PROJECT, 2024
** my_puterr.c
** File description:
** my_puterr
*/

#include <lib.h>

int my_puterr(char *str)
{
    int len = my_strlen(str);

    return write(2, str, len);
}
