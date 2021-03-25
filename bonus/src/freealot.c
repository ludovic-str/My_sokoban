/*
** EPITECH PROJECT, 2021
** free
** File description:
** free
*/

#include "include/soko.h"

void freedouble(char **tab)
{
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}

void freeall(obj_t *obj)
{
    freedouble(obj->buff);
    freedouble(obj->mapcp);
    free(obj->ox);
    free(obj->oy);
    free(obj->xi);
    free(obj->xj);
}