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
        for (int i = 0; obj->buff[i]; i++)
            mvprintw(LINES/2 + i - (my_tablen(obj->buff) / 2)
            , (COLS / 2) - (obj->size / 2), obj->buff[i]);
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
    keypad(stdscr, TRUE);
    curs_set(0);
    while (1) {
        getmaxyx(stdscr, obj->row, obj->col);
        checksize(obj);
        if (obj->end != 0)
            break;
    }
    endwin();
}

int main(int ac, char **av)
{
    obj_t *obj = malloc(sizeof(obj_t));

    if (ac != 2) {
        return (84);
    }
    usage(av);
    obj->fd = open(av[1], O_RDONLY);
    putinmap(obj);
    game(obj);
    while (obj->end == -2) {
        obj->fd = open(av[1], O_RDONLY);
        putinmap(obj);
        game(obj);
    }
    if (obj->end < 0)
        return (1);
    return (0);
}