/*
** EPITECH PROJECT, 2021
** title
** File description:
** title
*/

#include "include/soko.h"

void my_switchon(char c, obj_t * obj)
{
    if (obj->gamestyle == 2 && c != ' ' && c != '\t')
        attron(COLOR_PAIR(7));
    else if (obj->gamestyle == 3 && c != ' ' && c != '\t')
        attron(COLOR_PAIR(8));
}

void my_switchoff(char c, obj_t * obj)
{
    if (obj->gamestyle == 2 && c != ' ' && c != '\t')
        attroff(COLOR_PAIR(7));
    else if (obj->gamestyle == 3 && c != ' ' && c != '\t')
        attroff(COLOR_PAIR(8));
}