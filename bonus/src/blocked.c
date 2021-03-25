/*
** EPITECH PROJECT, 2021
** blocked
** File description:
** blocked
*/

#include "include/soko.h"

int buttom(obj_t * obj, int x)
{
    int i = obj->xi[x];
    int xnbr = 0;
    int onbr = 0;

    for (int j = obj->xj[x]; obj->buff[i][j] != '#'; j++) {
        onbr = (obj->mapcp[i][j] == 'O') ? onbr + 1 : onbr;
        xnbr = (obj->buff[i][j] == 'X') ? xnbr + 1 : xnbr;
        if (obj->buff[i + 1][j] == ' ')
            return (0);
    }
    for (int j = obj->xj[x] - 1; obj->buff[i][j] != '#'; j--) {
        onbr = (obj->mapcp[i][j] == 'O') ? onbr + 1 : onbr;
        xnbr = (obj->buff[i][j] == 'X') ? xnbr + 1 : xnbr;
        if (obj->buff[i + 1][j] == ' ')
            return (0);
    }
    if (xnbr <= onbr)
        return (0);
    return (-1);
}

int top(obj_t * obj, int x)
{
    int i = obj->xi[x];
    int xnbr = 0;
    int onbr = 0;

    for (int j = obj->xj[x]; obj->buff[i][j] != '#'; j++) {
        onbr = (obj->mapcp[i][j] == 'O') ? onbr + 1 : onbr;
        xnbr = (obj->buff[i][j] == 'X') ? xnbr + 1 : xnbr;
        if (obj->buff[i - 1][j] == ' ')
            return (0);
    }
    for (int j = obj->xj[x] - 1; obj->buff[i][j] != '#'; j--) {
        onbr = (obj->mapcp[i][j] == 'O') ? onbr + 1 : onbr;
        xnbr = (obj->buff[i][j] == 'X') ? xnbr + 1 : xnbr;
        if (obj->buff[i - 1][j] == ' ')
            return (0);
    }
    if (xnbr <= onbr)
        return (0);
    return (-1);
}

int right(obj_t * obj, int x)
{
    int j = obj->xj[x];
    int xnbr = 0;
    int onbr = 0;

    for (int i = obj->xi[x]; obj->buff[i][j] != '#'; i++) {
        onbr = (obj->mapcp[i][j] == 'O') ? onbr + 1 : onbr;
        xnbr = (obj->buff[i][j] == 'X') ? xnbr + 1 : xnbr;
        if (obj->buff[i][j + 1] == ' ')
            return (0);
    }
    for (int i = obj->xi[x] - 1; obj->buff[i][j] != '#'; i--) {
        onbr = (obj->mapcp[i][j] == 'O') ? onbr + 1 : onbr;
        xnbr = (obj->buff[i][j] == 'X') ? xnbr + 1 : xnbr;
        if (obj->buff[i][j + 1] == ' ')
            return (0);
    }
    if (xnbr <= onbr)
        return (0);
    return (-1);
}

int left(obj_t *obj, int x)
{
    int j = obj->xj[x];
    int xnbr = 0;
    int onbr = 0;

    for (int i = obj->xi[x]; obj->buff[i][j] != '#'; i++) {
        onbr = (obj->mapcp[i][j] == 'O') ? onbr + 1 : onbr;
        xnbr = (obj->buff[i][j] == 'X') ? xnbr + 1 : xnbr;
        if (obj->buff[i][j - 1] == ' ')
            return (0);
    }
    for (int i = obj->xi[x] - 1; obj->buff[i][j] != '#'; i--) {
        onbr = (obj->mapcp[i][j] == 'O') ? onbr + 1 : onbr;
        xnbr = (obj->buff[i][j] == 'X') ? xnbr + 1 : xnbr;
        if (obj->buff[i][j - 1] == ' ')
            return (0);
    }
    if (xnbr <= onbr)
        return (0);
    return (-1);
}