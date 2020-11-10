/*
** EPITECH PROJECT, 2019
** my_array_dup
** File description:
** dup array
*/

#include "../include/my.h"

int my_linelen(char **array)
{
    int i;

    for (i = 0; array[i]; i++) {
    }
    return (i);
}

char **my_array_dup(char **array)
{
    char **new = malloc(sizeof(char *) * ((my_linelen(array) + 1)));
    int i = 0;

    if (new == NULL)
        return (NULL);
    for (i = 0; array[i]; i++)
        new[i] = my_strdup(array[i]);
    new[i] = NULL;
    return (new);
}
