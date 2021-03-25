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
}

int abovex(obj_t *obj, int x)
{
    if (obj->buff[obj->xi[x]][obj->xj[x] + 1] == '#')
        return (right(obj, x));
    else
        return (left(obj, x));
}

int sidex(obj_t *obj, int x)
{
    if (obj->buff[obj->xi[x] + 1][obj->xj[x]] == '#')
        return (buttom(obj, x));
    else
        return (top(obj, x));
}

int checkxblocked(obj_t *obj, int i)
{
    if ((obj->buff[obj->xi[i] + 1][obj->xj[i]] == '#'
    || obj->buff[obj->xi[i] - 1][obj->xj[i]] == '#') &&
    obj->buff[obj->xi[i]][obj->xj[i] + 1] != '#' &&
    obj->buff[obj->xi[i]][obj->xj[i] - 1] != '#')
        return(sidex(obj, i));
    else if (obj->buff[obj->xi[i] + 1][obj->xj[i]] != '#'
    && obj->buff[obj->xi[i] - 1][obj->xj[i]] != '#' && (
    obj->buff[obj->xi[i]][obj->xj[i] + 1] == '#' ||
    obj->buff[obj->xi[i]][obj->xj[i] - 1] == '#'))
        return (abovex(obj, i));
    return (0);
}

void checkloose(obj_t *obj)
{
    searchmyx(obj);
    for (int i = 0; obj->xi[i] != -1; i++) {
        if ((obj->buff[obj->xi[i] + 1][obj->xj[i]] == '#' ||
        obj->buff[obj->xi[i] - 1][obj->xj[i]] == '#') &&
        (obj->buff[obj->xi[i]][obj->xj[i] + 1] == '#' ||
        obj->buff[obj->xi[i]][obj->xj[i] - 1] == '#') &&
        obj->mapcp[obj->xi[i]][obj->xj[i]] != 'O') {
            obj->end = -1;
            return;
        }
        else if (checkxblocked(obj, i) == -1) {
            obj->end = -1;
            return;
        }
    }
}