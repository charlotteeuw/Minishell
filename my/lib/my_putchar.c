/*
** EPITECH PROJECT, 2023
** $MY_PUTCHAR
** File description:
** Prints a character
*/

#include <lib.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
