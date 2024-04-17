/*
** EPITECH PROJECT, 2024
** my_freetab
** File description:
** frees an array
*/

#include <lib.h>

void my_freetab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}
