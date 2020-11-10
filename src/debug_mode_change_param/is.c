/*
** EPITECH PROJECT, 2019
** is
** File description:
** tetris
*/

#include "../../include/my.h"

int is_num (char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '9')
            return (0);
    return (1);
}

int is_param(char *str)
{
    for (int i = 0; ARG[i] != NULL; i++) {
        if (str[0] == '-' && str[1] == '-' &&
            compare_double(str, ARG[i]) == 1)
            return (2);
        else if (my_strcmp(str, ARG[i]) == 1)
            return (1);
    }
    return (0);
}

int is_separator(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '='; i++);
    for (i = i + 1; str[i]; i++)
        if (str[i] == ',' && str[i + 1])
            return (1);
    return (0);
}
