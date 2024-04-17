/*
** EPITECH PROJECT, 2024
** my_strcspn
** File description:
** calculates the lenght of the num of chars before
** 1rst occurence of character present in both the string
*/

#include <lib.h>

int check_match(const char *s2, const char *s1, int i)
{
    for (int j = 0; s2[j] != '\0'; j++) {
        if (s1[i] == s2[j])
            return 1;
    }
    return 0;
}

int my_strcspn(const char *s1, const char *s2)
{
    int occurence = 0;

    for (int i = 0; s1[i] != '\0'; i++) {
        if (check_match(s2, s1, i) == 1)
            return occurence;
        occurence++;
    }
    return my_strlen(s1);
}
