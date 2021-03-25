/*
** EPITECH PROJECT, 2021
** colorswitch
** File description:
** colorswitch
*/

#include "include/soko.h"

void printhash(obj_t *obj, int i, int j)
{
    attron(COLOR_PAIR(1));
    my_printw(obj, i, j);
    attroff(COLOR_PAIR(1));
}

void printx(obj_t *obj, int i, int j)
{
    attron(COLOR_PAIR(2));
    my_printw(obj, i, j);
    attroff(COLOR_PAIR(2));
}

void printo(obj_t *obj, int i, int j)
{
    attron(COLOR_PAIR(3));
    my_printw(obj, i, j);
    attroff(COLOR_PAIR(3));
}

void printp(obj_t *obj, int i, int j)
{
    attron(COLOR_PAIR(4));
    my_printw(obj, i, j);
    attroff(COLOR_PAIR(4));
}

void printspace(obj_t *obj, int i, int j)
{
    attron(COLOR_PAIR(5));
    my_printw(obj, i, j);
    attroff(COLOR_PAIR(5));
}