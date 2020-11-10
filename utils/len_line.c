/*
** EPITECH PROJECT, 2019
** len line
** File description:
** get nbr line in array
*/

#include "../include/my.h"

int len_line(char **array)
{
    int line = 0;

    for (int i = 0; array[i]; i++)
        line++;
    return (line + 1);
}
