/*
** EPITECH PROJECT, 2020
** str isalpha
** File description:
** only alphabetical caracter
*/

int my_str_isalpha(char const c)
{
    if (c < 'A' || 'Z' < c < 'a' || c > 'z') {
        return (0);
        }
    return (1);
}
