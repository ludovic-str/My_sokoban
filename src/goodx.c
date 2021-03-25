/*
** EPITECH PROJECT, 2021
** goodw
** File description:
** goodx
*/

#include "include/soko.h"

void searchmyx(obj_t *obj)
{
    int j = 0;
    int x = 0;

    for (int i = 0; obj->buff[i]; i++) {
        for (; obj->buff[i][j]; j++) {
            if (obj->buff[i][j] == 'X') {
                obj->xi[x] = i;
                obj->xj[x] = j;
                x++;
            }
        }
        j = 0;
    }
    obj->xi[x] = -1;
    obj->xj[x] = -1;
    obj->xnb = x;
}

void checkloose(obj_t *obj)
{
    int blocked = 0;
    searchmyx(obj);
    for (int i = 0; obj->xi[i] != -1; i++) {
        if ((obj->buff[obj->xi[i] + 1][obj->xj[i]] == '#' ||
        obj->buff[obj->xi[i] - 1][obj->xj[i]] == '#') &&
        (obj->buff[obj->xi[i]][obj->xj[i] + 1] == '#' ||
        obj->buff[obj->xi[i]][obj->xj[i] - 1] == '#') &&
        obj->mapcp[obj->xi[i]][obj->xj[i]] != 'O') {
            blocked++;
        }
    }
    if (blocked == obj->xnb)
        obj->end = -1;
    return;
}