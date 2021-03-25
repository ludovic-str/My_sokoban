/*
** EPITECH PROJECT, 2021
** winloose
** File description:
** winloose
*/

#include "include/soko.h"

void initlose(obj_t *obj)
{
    int fd = open("assets/lose", O_RDONLY);
    struct stat lose;
    char *losebuff = NULL;

    fstat(fd, &lose);
    losebuff = malloc(sizeof(char) * (lose.st_size + 2));
    for (int i = 0; i <= lose.st_size; i++)
        losebuff[i] = '\0';
    read(fd, losebuff, lose.st_size);
    losebuff[lose.st_size] = '\0';
    obj->losebuff = my_wordtowordarray(losebuff);
    free(losebuff);
    close(fd);
}

void initwin(obj_t *obj)
{
    int fd = open("assets/win", O_RDONLY);
    struct stat win;
    char *winbuff = NULL;

    fstat(fd, &win);
    winbuff = malloc(sizeof(char) * (win.st_size + 2));
    for (int i = 0; i <= win.st_size; i++)
        winbuff[i] = '\0';
    read(fd, winbuff, win.st_size);
    winbuff[win.st_size] = '\0';
    obj->winbuff = my_wordtowordarray(winbuff);
    free(winbuff);
    close(fd);
}

void mywin(obj_t *obj)
{
    initwin(obj);
    clear();
    for (int i = 0; obj->winbuff[i]; i++) {
        for (int j = 0; obj->winbuff[i][j]; j++) {
            my_switchon(obj->winbuff[i][j], obj);
            mvprintw(LINES / 2 - (my_tablen(obj->winbuff) / 2) + i,
            (COLS / 2) - (my_strlen(obj->winbuff[3]) / 2) + j,
            &obj->winbuff[i][j]);
            my_switchoff(obj->winbuff[i][j], obj);
        }
    }
    mvprintw(LINES / 2 + (my_tablen(obj->winbuff) / 2) + 8, (COLS / 2) -
    (my_strlen("Next Level") / 2), "Next Level");
    refresh();
    usleep(2000000);
    freedouble(obj->winbuff);
}

void myloose(obj_t *obj)
{
    initlose(obj);
    clear();
    for (int i = 0; obj->losebuff[i]; i++) {
        for (int j = 0; obj->losebuff[i][j]; j++) {
            my_switchon(obj->losebuff[i][j], obj);
            mvprintw(LINES / 2 - (my_tablen(obj->losebuff) / 2) + i,
            (COLS / 2) - (my_strlen(obj->losebuff[3]) / 2) + j,
            &obj->losebuff[i][j]);
            my_switchoff(obj->losebuff[i][j], obj);
        }
    }
    mvprintw(LINES / 2 + (my_tablen(obj->losebuff) / 2) + 8, (COLS / 2) -
    (my_strlen("Try Again") / 2), "Try Again");
    refresh();
    usleep(2000000);
    freedouble(obj->losebuff);
}

void winlose(obj_t *obj)
{
    if (obj->end == 1)
        mywin(obj);
    else if (obj->end == -1)
        myloose(obj);
}