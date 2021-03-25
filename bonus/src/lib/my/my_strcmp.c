/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** compare string
*/

#include "my.h"

int  my_strcmp(char  const *s1 , char  const *s2)
{
    int count_first = 0;
    int count_second = 0;

    for (int i = 0; s1[i]; i++) {
        count_first += (int)s1[i];
    }
    for (int i = 0; s2[i]; i++) {
        count_second += (int)s2[i];
    }
    if (count_first == count_second)
        return (0);
    else
        return (count_first - count_second);
}