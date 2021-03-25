/*
** EPITECH PROJECT, 2021
** error
** File description:
** error
*/

#include "include/soko.h"

void usage(char **av)
{
    if (my_strcmp(av[1], "-h") == 0) {
        my_printf("USAGE\n\t\t./my_sokoban map\n");
        my_printf("DESCRIPTION\n\t\tmap  file representing ");
        my_printf("the warehouse map, containing ‘#’ for walls,\n");
        my_printf("\t\t\t‘P’ for the player, ‘X’ for boxes and ‘O’ ");
        my_printf("for storage locations.\n");
        exit (0);
    }
}

int countchar(char **buff, char c)
{
    int count = 0;

    for (int i = 0; buff[i]; i++) {
        for (int j = 0; buff[i][j]; j++)
            count += (buff[i][j] == c) ? 1 : 0;
    }
    return (count);
}

int mainerror(char **buff, char *buffer)
{
    if (countchar(buff, 'P') != 1 || countchar(buff, 'X') == 0)
        exit(84);
    else if (countchar(buff, 'X') != countchar(buff, 'O'))
        exit(84);
    for (int i = 0; buffer[i]; i++) {
        if (buffer[i] != 'X' && buffer[i] != 'O' && buffer[i] != '\n' &&
        buffer[i] != '#' && buffer[i] != 'P' && buffer[i] != ' ' && buffer[i])
            exit(84);
    }
    return (0);
}