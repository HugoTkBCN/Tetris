/*
** EPITECH PROJECT, 2019
** malloc array
** File description:
** 2d array
*/

#include "../include/my.h"

char **malloc_2d_array(int nbr_lines, int nbr_cols)
{
    char **array = malloc(sizeof(char *) * (nbr_lines + 1));

    if (array == NULL)
        return (NULL);
    for (int i = 0; i < nbr_lines; i++) {
        array[i] = malloc(sizeof(char) * (nbr_cols + 1));
        if (array[i] == NULL)
            return (NULL);
    }
    return (array);
}
