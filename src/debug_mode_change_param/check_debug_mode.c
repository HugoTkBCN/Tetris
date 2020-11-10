/*
** EPITECH PROJECT, 2019
** check
** File description:
** debug mode
*/

#include "../../include/my.h"

int check_shape(char **shape, int height, int width)
{
    int real_width = get_real_width(shape);
    int real_height = get_real_height(shape);

    if (height != real_height || width != real_width)
        return (84);
}

int check_tetriminos(tetrimino_t tetrimino)
{
    if (tetrimino.height == -84 || tetrimino.width == -84 ||
        tetrimino.color == -84)
        return (84);
    else if (check_shape(tetrimino.shape, tetrimino.height,
                        tetrimino.width) == 84)
        return (84);
    return (0);
}
