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
    int xnb;
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
void usage(char **av);

#endif /* !soko */
