/*
** EPITECH PROJECT, 2019
** get debug mode
** File description:
** debug mode 2
*/

#include "../../include/my.h"

int get_width_tetrimino(char **tetrimino)
{
    char *width = malloc(sizeof(char) * (my_strlen(tetrimino[0]) + 1));
    int i = 0;

    if (width == NULL)
        return (-84);
    for (i = 0; tetrimino[0][i] != ' ' && tetrimino[0][i]; i++) {
        width[i] = tetrimino[0][i];
    }
    width[i] = '\0';
    return (str_to_int(width));
}

int get_height_tetrimino(char **tetrimino)
{
    char *height = malloc(sizeof(char) * (my_strlen(tetrimino[0]) + 1));
    int i = 0;
    int y = 0;

    if (height == NULL)
        return (-84);
    for (i = 0; tetrimino[0][i] != ' ' && tetrimino[0][i]; i++);
    for (i = i + 1; tetrimino[0][i] != ' ' && tetrimino[0][i]; i++) {
        height[y++] = tetrimino[0][i];
    }
    height[y] = '\0';
    return (str_to_int(height));
}

char **get_shape_tetrimino(char **tetrimino)
{
    char **shape = malloc(sizeof(char *) * (get_real_height(tetrimino) + 1));
    int i = 0;
    int y = 0;
    int c = 0;

    if (shape == NULL)
        return (NULL);
    for (int y = 1; tetrimino[y]; y++) {
        shape[c] = malloc(sizeof(char) * (my_strlen(tetrimino[y]) + 1));
        if (shape[c] == NULL)
            return (NULL);
        for (i = 0; tetrimino[y][i]; i++)
            shape[c][i] = tetrimino[y][i];
        i = shape[c][i - 1] == '\n' ? i - 1 : i;
        shape[c++][i] = '\0';
    }
    shape[c] = NULL;
    return (shape);
}

int get_nbr_tetriminos(char **files_name)
{
    int i = 0;

    for (i = 0; files_name[i]; i++);
    return (i);
}

char *get_name_tetrimino(char *long_name)
{
    char *name = malloc(sizeof(char) * (my_strlen(long_name) + 1));
    int i = 0;
    int y = 0;

    if (name == NULL)
        return (NULL);
    for (i = 0; long_name[i] != '.'; i++)
        name[y++] = long_name[i];
    name[y] = '\0';
    return (name);
}
