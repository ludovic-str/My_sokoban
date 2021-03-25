/*
** EPITECH PROJECT, 2021
** colormain
** File description:
** colormaib
*/

#include "include/soko.h"

void my_printw(obj_t *obj, int i, int j)
{
    mvprintw(LINES/2 + i - (my_tablen(obj->buff) / 2)
    , (COLS / 2) - (obj->size / 2) + j, &obj->buff[i][j]);
}

void colorinit(obj_t *obj)
{
    if (obj->gamestyle == 1) {
        init_pair(1, COLOR_WHITE, COLOR_BLACK);
        init_pair(2, COLOR_WHITE, COLOR_BLACK);
        init_pair(3, COLOR_WHITE, COLOR_BLACK);
        init_pair(4, COLOR_WHITE, COLOR_BLACK);
    }
    else if (obj->gamestyle == 2) {
        init_pair(1, COLOR_GREEN, COLOR_BLACK);
        init_pair(2, COLOR_CYAN, COLOR_BLACK);
        init_pair(3, COLOR_RED, COLOR_BLACK);
        init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    } else {
        init_pair(1, COLOR_GREEN, COLOR_GREEN);
        init_pair(2, COLOR_CYAN, COLOR_CYAN);
        init_pair(3, COLOR_RED, COLOR_RED);
        init_pair(4, COLOR_YELLOW, COLOR_YELLOW);
    }
    init_pair(5, COLOR_BLACK, COLOR_BLACK);
}

void my_switch(obj_t *obj, int i, int j)
{
    switch (obj->buff[i][j])
    {
    case '#':
        printhash(obj, i, j);
        break;
    case 'X':
        printx(obj, i, j);
        break;
    case 'O':
        printo(obj, i, j);
        break;
    case 'P':
        printp(obj, i, j);
        break;
    case ' ':
        printspace(obj, i, j);
        break;
    }
}

void colormain(obj_t *obj)
{
    for (int i = 0; obj->buff[i]; i++) {
        for (int j = 0; obj->buff[i][j]; j++) {
            my_switch(obj, i, j);
        }
    }
}