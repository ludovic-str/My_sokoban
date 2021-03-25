/*
** EPITECH PROJECT, 2021
** menu
** File description:
** menu
*/

#include "include/soko.h"

void changegamestat(obj_t *obj)
{
    if (obj->menupos == 1)
        obj->menustate = 1;
    else if (obj->menupos == 2) {
        obj->gamestyle++;
        if (obj->gamestyle == 4)
            obj->gamestyle = 1;
    } else {
        obj->menustate = -1;
        obj->end = -5;
    }
}

void choisemenu(obj_t *obj)
{
    if (obj->menupos == 1) {
        attron(COLOR_PAIR(6));
        mvprintw(LINES / 2 + 1, COLS / 2 - 9 + 1, "      Start    ");
        attroff(COLOR_PAIR(6));
        printsettings(obj);
        mvprintw(LINES / 2 + 3, COLS / 2 - 9 + 1, "      Quit     ");
    }
    else if (obj->menupos == 2) {
        mvprintw(LINES / 2 + 1, COLS / 2 - 9 + 1, "      Start    ");
        attron(COLOR_PAIR(6));
        printsettings(obj);
        attroff(COLOR_PAIR(6));
        mvprintw(LINES / 2 + 3, COLS / 2 - 9 + 1, "      Quit     ");
    } else {
        mvprintw(LINES / 2 + 1, COLS / 2 - 9 + 1, "      Start    ");
        printsettings(obj);
        attron(COLOR_PAIR(6));
        mvprintw(LINES / 2 + 3, COLS / 2 - 9 + 1, "      Quit     ");
        attroff(COLOR_PAIR(6));
    }
}

void printmenu(obj_t *obj)
{
    init_pair(6, COLOR_BLACK, COLOR_WHITE);
    init_pair(7, COLOR_GREEN, COLOR_BLACK);
    init_pair(8, COLOR_GREEN, COLOR_GREEN);
    printtitle(obj);
    printaround(obj);
    choisemenu(obj);
}

void changeplace(obj_t *obj)
{
    switch (getch())
    {
    case KEY_DOWN:
        if (obj->menupos < 3)
            obj->menupos++;
        break;
    case KEY_UP:
        if (obj->menupos > 1)
            obj->menupos--;
        break;
    case '\n':
        changegamestat(obj);
        break;
    }
}

int menu(obj_t *obj)
{
    inittitle(obj);
    obj->menupos = 1;
    obj->menustate = 0;
    if (obj->previousend == -2)
        return(0);
    while (obj->menustate == 0) {
        clear();
        printmenu(obj);
        changeplace(obj);
        refresh();
    }
    freedouble(obj->titlebuff);
    return (0);
}