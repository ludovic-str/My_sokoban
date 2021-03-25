/*
** EPITECH PROJECT, 2021
** goodo
** File description:
** goodo
*/

#include "include/soko.h"

void checkwin(obj_t *obj)
{
    for (int i = 0; obj->ox[i] != -1; i++) {
        if (obj->buff[obj->ox[i]][obj->oy[i]] != 'X')
            return;
    }
    obj->end = 1;
}

void replacemyo(obj_t *obj)
{
    for (int i = 0; obj->ox[i] != -1; i++) {
        if (obj->buff[obj->ox[i]][obj->oy[i]] == ' ')
            obj->buff[obj->ox[i]][obj->oy[i]] = 'O';
    }
}

int searchonbr(obj_t *obj)
{
    int j = 0;
    int n = 0;

    for (int i = 0; obj->buff[i]; i++) {
        for (; obj->buff[i][j]; j++) {
            if (obj->buff[i][j] == 'O')
                n++;
        }
        j = 0;
    }
    return (n);
}

void searchmyo(obj_t *obj)
{
    int j = 0;
    int x = 0;

    obj->ox = malloc(sizeof(int) * (searchonbr(obj) + 1));
    obj->oy = malloc(sizeof(int) * (searchonbr(obj) + 1));
    obj->xi = malloc(sizeof(int) * (searchonbr(obj) + 1));
    obj->xj = malloc(sizeof(int) * (searchonbr(obj) + 1));
    for (int i = 0; obj->buff[i]; i++) {
        for (; obj->buff[i][j]; j++) {
            if (obj->buff[i][j] == 'O') {
                obj->ox[x] = i;
                obj->oy[x] = j;
                x++;
            }
        }
        j = 0;
    }
    obj->ox[x] = -1;
    obj->oy[x] = -1;
}