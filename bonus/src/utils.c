/*
** EPITECH PROJECT, 2021
** utils
** File description:
** utils
*/

#include "include/soko.h"

int bigestl(char **tab)
{
    int bigest = 0;

    for (int i = 0; tab[i]; i++) {
        if (my_strlen(tab[i]) > bigest)
            bigest = my_strlen(tab[i]);
    }
    return (bigest);
}

int my_tablen(char **tab)
{
    int i = 0;

    for (; tab[i]; i++);
    return (i);
}

void searchmyp(obj_t *obj)
{
    int ppose = 0;
    int j = 0;

    for (int i = 0; obj->buff[i]; i++) {
        for (; obj->buff[i][j] && obj->buff[i][j] != 'P'; j++);
        if (obj->buff[i][j] == 'P') {
            obj->px = i;
            obj->py = j;
            break;
        }
        j = 0;
    }
}

char **mallocdouble(int countword, int len)
{
    char **array;
    int h = 0;

    array = malloc(sizeof(char *) * (countword + 2));
    for (; h < countword; h++)
        array[h] = malloc(sizeof(char) * (len + 2));
    return (array);
}

char **my_wordtowordarray(char *str)
{
    int countword = 1;
    int h = 0;
    int b = 0;
    char **array;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '\n')
            countword += 1;
    }
    array = mallocdouble(countword, my_strlen(str));
    for (int i = 0; i <= my_strlen(str); i++) {
        for (; str[i] != '\n' && str[i] != '\0'; i++) {
            array[h][b] = str[i];
            b++;
        }
        array[h][b] = '\0';
        h++;
        b = 0;
    }
    array[h] = NULL;
    return (array);
}