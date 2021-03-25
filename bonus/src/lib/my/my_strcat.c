/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** concacenate two strings
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    for (; dest[i] != '\0'; i++);
    for (; src[j] != '\0'; j++) {
        dest [i + j] = src[j];
    }
    dest[i + j] = '\0';
    return (dest);
}