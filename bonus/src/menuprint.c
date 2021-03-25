/*
** EPITECH PROJECT, 2021
** menuprint
** File description:
** menuprint
*/

#include "include/soko.h"

void printaround(obj_t *obj)
{
    if (obj->gamestyle == 2)
        attron(COLOR_PAIR(7));
    else if (obj->gamestyle == 3)
        attron(COLOR_PAIR(8));
    mvprintw(LINES / 2, COLS / 2 - 9, "+---------------+");
    mvprintw(LINES / 2 + 1, COLS / 2 - 9, "|               |");
    mvprintw(LINES / 2 + 2, COLS / 2 - 9, "|               |");
    mvprintw(LINES / 2 + 3, COLS / 2 - 9, "|               |");
    mvprintw(LINES / 2 + 4, COLS / 2 - 9, "+---------------+");
    if (obj->gamestyle == 2)
        attroff(COLOR_PAIR(7));
    else if (obj->gamestyle == 3)
        attroff(COLOR_PAIR(8));
}

void printsettings(obj_t *obj)
{
    if (obj->gamestyle == 1)
        mvprintw(LINES / 2 + 2, COLS / 2 - 9 + 1, "Video Mode : 1 ");
    else if (obj->gamestyle == 2)
        mvprintw(LINES / 2 + 2, COLS / 2 - 9 + 1, "Video Mode : 2 ");
    else
        mvprintw(LINES / 2 + 2, COLS / 2 - 9 + 1, "Video Mode : 3 ");
}

void printtitle(obj_t *obj)
{
    for (int i = 0; obj->titlebuff[i]; i++) {
        for (int j = 0; obj->titlebuff[i][j]; j++) {
            my_switchon(obj->titlebuff[i][j], obj);
            mvprintw(i + 1, (COLS / 2) -
            (my_strlen(obj->titlebuff[3]) / 2) + j, &obj->titlebuff[i][j]);
            my_switchoff(obj->titlebuff[i][j], obj);
        }
    }
}

void inittitle(obj_t *obj)
{
    int fd = open("assets/title", O_RDONLY);
    struct stat title;
    char *titlebuff = NULL;

    fstat(fd, &title);
    titlebuff = malloc(sizeof(char) * (title.st_size + 2));
    for (int i = 0; i <= title.st_size; i++)
        titlebuff[i] = '\0';
    read(fd, titlebuff, title.st_size);
    titlebuff[title.st_size] = '\0';
    obj->titlebuff = my_wordtowordarray(titlebuff);
    free(titlebuff);
    close(fd);
}