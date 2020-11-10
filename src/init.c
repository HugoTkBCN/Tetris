/*
** EPITECH PROJECT, 2019
** init
** File description:
** tetris
*/

#include "../include/my.h"

void init_colors(void)
{
    for (int i = 0; i <= NBR_COLOR_MAX; i++)
        init_pair(i, i, COLOR_BLACK);
}

data_game_t *init_data_game(param_t *param)
{
    data_game_t *data_game = malloc(sizeof(data_game_t) * 2);

    if (data_game == NULL)
        return (NULL);
    srand(time(0));
    data_game->next_tetriminos = rand() % param->nbr_tetriminos;
    while (data_game->next_tetriminos == 0 ||
            param->tetriminos[data_game->next_tetriminos].good == 0)
        data_game->next_tetriminos = rand() % param->nbr_tetriminos;
    data_game->is_falling = 0;
    data_game->is_line_empty = 0;
    return (data_game);
}
