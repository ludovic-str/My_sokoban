/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "include/soko.h"

int checksize(obj_t *obj)
{
    clear();
    if (obj->col < (bigestl(obj->buff) + (COLS / 2)) ||
    obj->row < (my_tablen(obj->buff) + (LINES / 2))) {
        mvprintw(LINES/2, (COLS / 2), "To small window size");
    } else {
        colormain(obj);
        obj->keyp = getch();
        moveplayer(obj);
        replacemyo(obj);
        checkwin(obj);
        checkloose(obj);
        if (obj->end != 0)
            return (1);
    }
    refresh();
    return (0);
}

int game(obj_t *obj)
{
    obj->end = 0;
    obj->size = bigestl(obj->buff);
    searchmyp(obj);
    searchmyo(obj);
    initscr();
    start_color();
    keypad(stdscr, TRUE);
    curs_set(0);
    menu(obj);
    colorinit(obj);
    while (1) {
        if (obj->end != 0)
            break;
        getmaxyx(stdscr, obj->row, obj->col);
        checksize(obj);
    }
    winlose(obj);
    endwin();
}

int main(int ac, char **av)
{
    obj_t *obj = malloc(sizeof(obj_t));

    obj->previousend = 0;
    obj->gamestyle = 1;
    if (ac != 2) {
        return (84);
    }
    usage(av);
    obj->fd = open(av[1], O_RDONLY);
    putinmap(obj);
    game(obj);
    obj->previousend = obj->end;
    while(obj->end != -5) {
        obj->fd = open(av[1], O_RDONLY);
        putinmap(obj);
        game(obj);
        obj->previousend = obj->end;
    }
    freeall(obj);
    return (0);
}