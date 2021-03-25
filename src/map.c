/*
** EPITECH PROJECT, 2021
** map
** File description:
** map
*/

#include "include/soko.h"

void putinmap(obj_t *obj)
{
    struct stat strs;
    char *buff = NULL;
    obj->end = 0;

    if (obj->fd < 0)
        exit(84);
    fstat(obj->fd, &strs);
    buff = malloc(sizeof(char) * (strs.st_size + 2));
    for (int i = 0; i <= strs.st_size; i++)
        buff[i] = '\0';
    read(obj->fd, buff, strs.st_size);
    buff[strs.st_size] = '\0';
    obj->buff = my_wordtowordarray(buff);
    mainerror(obj->buff, buff);
    obj->mapcp = my_wordtowordarray(buff);
    close(obj->fd);
}