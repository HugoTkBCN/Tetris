/*
** EPITECH PROJECT, 2019
** put_debug mode info
** File description:
** tetriminos
*/

#include "../../include/my.h"

tetrimino_t convert_to_struct(char **array)
{
    tetrimino_t tetrimino;

    tetrimino.height = get_height_tetrimino(array);
    tetrimino.save_height = tetrimino.height;
    tetrimino.width = get_width_tetrimino(array);
    tetrimino.save_width = tetrimino.width;
    tetrimino.color = get_color_tetrimino(array);
    tetrimino.shape = get_shape_tetrimino(array);
    tetrimino.save_shape = my_array_dup(tetrimino.shape);
    return (tetrimino);
}

void put_error(tetrimino_t tetrimino)
{
    my_putstr("Tetriminos : Name ");
    my_putstr(tetrimino.name);
    my_putstr(" : Error\n");
}

void print_tetriminos_info(tetrimino_t tetrimino)
{
    my_putstr("Tetriminos : Name ");
    my_putstr(tetrimino.name);
    my_putstr(" : Size ");
    my_put_nbr(tetrimino.width);
    my_putstr("*");
    my_put_nbr(tetrimino.height);
    my_putstr(" : Color ");
    my_put_nbr(tetrimino.color);
    my_putstr(" :\n");
    for (int i = 0; tetrimino.shape[i]; i++) {
        my_putstr(tetrimino.shape[i]);
        my_putstr("\n");
    }
}

tetrimino_t *get_tetriminos_info(char **files_name, int nbr_tetriminos)
{
    tetrimino_t *tetriminos = malloc(sizeof(tetrimino_t) *
                                    (nbr_tetriminos + 1));
    char **tetriminos_char = NULL;

    if (tetriminos == NULL)
        return (NULL);
    for (int i = 0; files_name[i]; i++) {
        tetriminos_char = get_tetriminos(mem_alloc(PATH_TETRIMINOS,
                                                files_name[i]));
        if (tetriminos_char == NULL) {
            my_putstr("Bad tetriminos config file\n");
            return (NULL);
        }
        tetriminos[i] = convert_to_struct(tetriminos_char);
        tetriminos[i].name = get_name_tetrimino(files_name[i]);
        tetriminos[i].x = 0;
        tetriminos[i].y = 0;
    }
    return (tetriminos);
}
