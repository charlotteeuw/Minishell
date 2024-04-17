/*
** EPITECH PROJECT, 2024
** my_itoa
** File description:
** convert int into string
*/

#include <lib.h>

int count_size(int nb)
{
    int size = 0;

    if (0 <= nb && nb < 10)
        return 1;
    while (nb != 0) {
        nb = nb / 10;
        size++;
    }
    return size;
}

char *my_itoa(int nb)
{
    int size = count_size(nb);
    char *output = malloc(sizeof(char) * size + 1);
    int i = size - 1;

    output[size] = '\0';
    if (0 <= nb && nb < 10)
        output[0] = nb + '0';
    while (nb != 0) {
        output[i] = nb % 10 + '0';
        nb = nb / 10;
        i--;
    }
    return output;
}
