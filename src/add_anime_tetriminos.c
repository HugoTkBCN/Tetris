/*
** EPITECH PROJECT, 2019
** add tetriminos anime
** File description:
** tetris
*/

#include "../include/my.h"

void move_tetriminos_in_board(board_t *main_board, tetrimino_t *tetrimino,
                            data_game_t *data_game)
{
    int stop = 0;

    if (verif_down(tetrimino, main_board) == 1)
        stop = 1;
    for (int y = tetrimino->height - 1; y >= 0 && stop == 0; y--)
        for (int i = tetrimino->width - 1; i >= 0; i--)
            if (tetrimino->shape[y][i] == '*') {
                main_board->board[tetrimino->y + y][tetrimino->x + i] = ' ';
                main_board->board[tetrimino->y + y + 1][tetrimino->x + i] =
                    tetrimino->color;
            }
    if (stop == 0)
        tetrimino->y += 1;
    else
        data_game->is_falling = 0;
}

void add_tetriminos_to_main_board(board_t *main_board, tetrimino_t tetrimino,
                                data_game_t *data_game)
{
    for (int y = 0; tetrimino.shape[y]; y++)
        for (int i = 0; tetrimino.shape[y][i]; i++)
            main_board->board[tetrimino.y + 1][tetrimino.x + i] =
                tetrimino.shape[y][i] == '*' ?
                tetrimino.color : tetrimino.shape[y][i];
    data_game->is_falling = 2;
}

int fall_tetriminos(param_t *param, all_boards_t *all_board,
                    data_game_t *data_game)
{
    int actual = 0;

    data_game->actual_tetriminos = data_game->next_tetriminos;
    actual = data_game->actual_tetriminos;
    data_game->next_tetriminos = rand() % param->nbr_tetriminos;
    while (data_game->next_tetriminos == 0 ||
            param->tetriminos[data_game->next_tetriminos].good == 0)
        data_game->next_tetriminos = rand() % param->nbr_tetriminos;
    data_game->is_falling = 1;
    param->tetriminos[actual].shape =
        my_array_dup(param->tetriminos[actual].save_shape);
    param->tetriminos[actual].x = (all_board->main_board->nbr_cols / 2)
        - (param->tetriminos[data_game->actual_tetriminos].height / 2);
    param->tetriminos[actual].y = 1;
    param->tetriminos[actual].width = param->tetriminos[actual].save_width;
    param->tetriminos[actual].height = param->tetriminos[actual].save_height;
    add_tetriminos_to_main_board(all_board->main_board,
    param->tetriminos[actual], data_game);
    return (add_tetriminos_to_next_board(all_board->next_board,
            param->tetriminos[actual]));
}

int add_anime_tetriminos(param_t *param, all_boards_t *all_board,
                        data_game_t *data_game)
{
    int ret = 0;

    if (data_game->is_falling == 0) {
        srand(time(0));
        ret = fall_tetriminos(param, all_board, data_game);
    } else if (data_game->is_falling == 2) {
        move_tetriminos_in_board(all_board->main_board,
        &param->tetriminos[data_game->actual_tetriminos], data_game);
    } else {
        add_tetriminos_to_main_board(all_board->main_board,
        param->tetriminos[data_game->actual_tetriminos], data_game);
    }
    return (ret);
}
