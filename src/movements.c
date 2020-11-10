/*
** EPITECH PROJECT, 2019
** movements
** File description:
** tetris
*/

#include "../include/my.h"

void go_left(board_t *board, param_t *param, data_game_t *data_game,
            tetrimino_t *tetrimino)
{
    int stop = 0;

    if (verif_down(tetrimino, board) == 1 || verif_left(tetrimino, board) == 1)
        stop = 1;
    for (int y = 0; y < tetrimino->height && stop == 0; y++)
        for (int i = 0; i < tetrimino->width; i++)
            if (tetrimino->shape[y][i] == '*') {
                board->board[tetrimino->y + y][tetrimino->x + i] = ' ';
                board->board[tetrimino->y + y][tetrimino->x + i - 1] =
                    tetrimino->color;
            }
    if (stop == 0)
        tetrimino->x -= 1;
}

void go_right(board_t *board, param_t *param, data_game_t *data_game,
            tetrimino_t *tetrimino)
{
    int stop = 0;

    if (verif_down(tetrimino, board) == 1 || verif_right(tetrimino, board) == 1)
        stop = 1;
    for (int y = tetrimino->height - 1; y >= 0 && stop == 0; y--)
        for (int i = tetrimino->width - 1; i >= 0; i--)
            if (tetrimino->shape[y][i] == '*') {
                board->board[tetrimino->y + y][tetrimino->x + i] = ' ';
                board->board[tetrimino->y + y][tetrimino->x + i + 1] =
                    tetrimino->color;
            }
    if (stop == 0)
        tetrimino->x += 1;
}

char **rotate_tetrimino(char **shape, tetrimino_t tetrimino)
{
    char *tmp = malloc(sizeof(char) * (tetrimino.height + 1));
    char **new_shape = malloc(sizeof(char *) * (tetrimino.width + 1));
    int i = 0;
    int y = 0;

    for (y = 0; y < tetrimino.width; y++) {
        for (i = 0; shape[i]; i++) {
            tmp[i] = shape[i][y];
        }
        tmp[i] = '\0';
        new_shape[y] = my_strdup(tmp);
    }
    new_shape[y] = NULL;
    return (new_shape);
}

void turn(board_t *board, param_t *param, data_game_t *data_game,
        tetrimino_t *tetrimino)
{
    for (int y = tetrimino->height - 1; y >= 0; y--)
        for (int i = tetrimino->width - 1; i >= 0; i--)
            if (tetrimino->shape[y][i] == '*') {
                board->board[tetrimino->y + y][tetrimino->x + i] = ' ';
            }
    tetrimino->shape = rotate_tetrimino(tetrimino->shape, *tetrimino);
    tetrimino->width = tetrimino->height;
    tetrimino->height = tetrimino->save_width;
    add_tetriminos_to_main_board(board, *tetrimino, data_game);
}

void drop(board_t *board, param_t *param, data_game_t *data_game,
        tetrimino_t *tetrimino)
{
    move_tetriminos_in_board(board, tetrimino, data_game);
}
