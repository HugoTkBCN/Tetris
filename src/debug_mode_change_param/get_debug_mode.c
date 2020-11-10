/*
** EPITECH PROJECT, 2019
** get
** File description:
** debug mode 1
*/

#include "../../include/my.h"

int get_nbr_line(char *filepath)
{
    FILE *fd = fopen(filepath, "r");
    size_t size = 0;
    char *line = NULL;
    int nbr_line = 0;

    if (fd == NULL)
        return (-1);
    for (int i = 0; getline(&line, &size, fd) != -1; i++) {
        nbr_line++;
    }
    fclose(fd);
    return (nbr_line);
}

char **get_tetriminos(char *filepath)
{
    char **tetriminos = malloc(sizeof(char *) * (get_nbr_line(filepath) + 1));
    FILE *fd = fopen(filepath, "r");
    size_t size = 0;
    char *line = NULL;
    int i = 0;

    if (fd == NULL || tetriminos == NULL)
        return (NULL);
    for (i = 0; getline(&line, &size, fd) != -1; i++)
        tetriminos[i] = my_strdup(line);
    if (i == 0)
        return (NULL);
    tetriminos[i] = NULL;
    fclose(fd);
    return (tetriminos);
}

int get_real_width(char **array)
{
    int i = 0;
    int tmp = 1;

    for (int y = 0; array[y]; y++) {
        for (i = 0; array[y][i]; i++) {
        }
        i = array[y][i - 1] == ' ' ? i - 1 : i;
        if (tmp < i)
            tmp = i;
    }
    return (tmp);
}

int get_real_height(char **array)
{
    int y = 0;

    for (y = 0; array[y]; y++) {
        for (int i = 0; array[y][i]; i++) {
        }
    }
    return (y);
}

int get_color_tetrimino(char **tetrimino)
{
    char *color = malloc(sizeof(char) * (my_strlen(tetrimino[0]) + 1));
    int i = 0;
    int y = 0;

    if (color == NULL)
        return (-84);
    for (i = 0; tetrimino[0][i] != ' ' && tetrimino[0][i]; i++);
    for (i = i + 1; tetrimino[0][i] != ' ' && tetrimino[0][i]; i++);
    for (i = i + 1; tetrimino[0][i] != ' ' && tetrimino[0][i]; i++)
        color[y++] = tetrimino[0][i];
    color[y - 1] = '\0';
    if (i != my_strlen(tetrimino[0]))
        return (-84);
    return (str_to_int(color));
}
