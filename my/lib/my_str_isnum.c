/*
** EPITECH PROJECT, 2023
** $MY_STR_ISNUM
** File description:
** Checks if the str contains numbers
*/

#include <lib.h>

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            continue;
        } else {
            return 0;
        }
    }
    return 1;
}
