/*
** EPITECH PROJECT, 2023
** $MY_STRLEN
** File description:
** Counts the number of characters in a string
*/

#include <lib.h>

int my_strlen(char const *str)
{
    int count = 0;
    int i = 0;

    if (str == NULL)
        return count;
    while (str[i] != '\0'){
        count++;
        i++;
    }
    return count;
}
