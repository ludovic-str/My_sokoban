/*
** EPITECH PROJECT, 2021
** soko
** File description:
** soko
*/

#ifndef soko
#define soko

#include <curses.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../lib/my/my.h"

typedef struct obj_s {
    char **buff;
    int px;
    int py;
    int keyp;
    int row;
    int col;
    char previous;
    int size;
    char **mapcp;
    int *ox;
    int *oy;
    int *xi;
    int *xj;
    int fd;
    int end;
    int menustate;
    int menupos;
    int previousend;
    int gamestyle;
    char **titlebuff;
    char **winbuff;
    char **losebuff;
} obj_t;

char **my_wordtowordarray(char *str);
int mainerror(char **buff, char *buffer);
void searchmyp(obj_t *obj);
void moveplayer(obj_t *obj);
int my_tablen(char **tab);
int bigestl(char **tab);
void searchmyo(obj_t *obj);
void replacemyo(obj_t *obj);
void checkwin(obj_t *obj);
void putinmap(obj_t *obj);
int game(obj_t *obj);
void checkloose(obj_t *obj);
int top(obj_t * obj, int x);
int buttom(obj_t * obj, int x);
int right(obj_t * obj, int x);
int left(obj_t *obj, int x);
void usage(char **av);
void colormain(obj_t *obj);
void colorinit(obj_t *obj);
void printhash(obj_t *obj, int i, int j);
void printx(obj_t *obj, int i, int j);
void printo(obj_t *obj, int i, int j);
void printp(obj_t *obj, int i, int j);
void my_printw(obj_t *obj, int i, int j);
void replay(obj_t *obj);
void printspace(obj_t *obj, int i, int j);
int menu(obj_t *obj);
void printsettings(obj_t *obj);
void printaround(obj_t *obj);
void inittitle(obj_t *obj);
void printtitle(obj_t *obj);
void my_switchoff(char c, obj_t * obj);
void my_switchon(char c, obj_t * obj);
void winlose(obj_t *obj);
void freeall(obj_t *obj);
void freedouble(char **tab);

#endif /* !soko */
