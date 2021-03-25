/*
** EPITECH PROJECT, 2021
** moverplayer
** File description:
** moveplayer
*/

#include "include/soko.h"

void moveup(obj_t *obj)
{
    obj->previous = obj->buff[obj->px][obj->py];
    if (obj->buff[obj->px - 1][obj->py] == 'X'
    && (obj->buff[obj->px - 2][obj->py] == ' ' ||
    obj->buff[obj->px - 2][obj->py] == 'O')){
        obj->buff[obj->px][obj->py] = ' ';
        obj->buff[obj->px - 1][obj->py] = 'P';
        obj->buff[obj->px - 2][obj->py] = 'X';
        obj->px--;
    }
    else if (obj->buff[obj->px - 1][obj->py] != '#' &&
    obj->buff[obj->px - 1][obj->py] != 'X') {
        obj->buff[obj->px][obj->py] = ' ';
        obj->buff[obj->px - 1][obj->py] = 'P';
        obj->px--;
    }
}

void movedown(obj_t *obj)
{
    obj->previous = obj->buff[obj->px][obj->py];
    if (obj->buff[obj->px + 1][obj->py] == 'X'
    && (obj->buff[obj->px + 2][obj->py] == ' ' ||
    obj->buff[obj->px + 2][obj->py] == 'O')) {
        obj->buff[obj->px][obj->py] = ' ';
        obj->buff[obj->px + 1][obj->py] = 'P';
        obj->buff[obj->px + 2][obj->py] = 'X';
        obj->px++;
    }
    else if (obj->buff[obj->px + 1][obj->py] != '#' &&
    obj->buff[obj->px + 1][obj->py] != 'X') {
        obj->buff[obj->px][obj->py] = ' ';
        obj->buff[obj->px + 1][obj->py] = 'P';
        obj->px++;
    }
}

void moveright(obj_t *obj)
{
    obj->previous = obj->buff[obj->px][obj->py];
    if (obj->buff[obj->px][obj->py + 1] == 'X'
    && (obj->buff[obj->px][obj->py + 2] == 'O' ||
    obj->buff[obj->px][obj->py + 2] == ' ')) {
        obj->buff[obj->px][obj->py] = ' ';
        obj->buff[obj->px][obj->py + 1] = 'P';
        obj->buff[obj->px][obj->py + 2] = 'X';
        obj->py++;
    }
    else if (obj->buff[obj->px][obj->py + 1] != '#' &&
    obj->buff[obj->px][obj->py + 1] != 'X') {
        obj->buff[obj->px][obj->py] = ' ';
        obj->buff[obj->px][obj->py + 1] = 'P';
        obj->py++;
    }
}

void moveleft(obj_t *obj)
{
    obj->previous = obj->buff[obj->px][obj->py];
    if (obj->buff[obj->px][obj->py - 1] == 'X'
    && (obj->buff[obj->px][obj->py - 2] == ' ' ||
    obj->buff[obj->px][obj->py - 2] == 'O')) {
        obj->buff[obj->px][obj->py] = ' ';
        obj->buff[obj->px][obj->py - 1] = 'P';
        obj->buff[obj->px][obj->py - 2] = 'X';
        obj->py--;
    }
    else if (obj->buff[obj->px][obj->py - 1] != '#' &&
    obj->buff[obj->px][obj->py - 1] != 'X') {
        obj->buff[obj->px][obj->py] = ' ';
        obj->buff[obj->px][obj->py - 1] = 'P';
        obj->py--;
    }
}

void moveplayer(obj_t *obj)
{
    switch (obj->keyp)
    {
    case KEY_UP:
        moveup(obj);
        break;
    case KEY_DOWN:
        movedown(obj);
        break;
    case KEY_RIGHT:
        moveright(obj);
        break;
    case KEY_LEFT:
        moveleft(obj);
        break;
    case ' ':
        obj->end = -2;
        break;
    case KEY_BACKSPACE:
        obj->end = -3;
        break;
    }
}