/*
** EPITECH PROJECT, 2019
** verif moves
** File description:
** tetris
*/

#include "../include/my.h"

int verif_left(tetrimino_t *tetrimino, board_t *board)
{
    for (int i = 0; i < tetrimino->height; i++)
        if (board->board[tetrimino->y + i][tetrimino->x - 1] != ' ')
            return (1);
    return (0);
}

int verif_right(tetrimino_t *tetrimino, board_t *board)
{
    for (int i = 0; i < tetrimino->height; i++)
        if (board->board[tetrimino->y + i][tetrimino->x +
        my_strlen(tetrimino->shape[i])] != ' ')
            return (1);
    return (0);
}

int verif_down(tetrimino_t *tetrimino, board_t *board)
{
    int stop = 0;

    for (int  i = 0; i < tetrimino->width; i++)
        if (tetrimino->shape[tetrimino->height - 1][i] == '*' &&
            board->board[tetrimino->y +
            (tetrimino->height == 1 ? 2 :
            tetrimino->height)][tetrimino->x + i] != ' ')
            stop = 1;
    for (int y = 0; y < tetrimino->height - 1; y++)
        for (int  i = 0; tetrimino->shape[y][i] == '*'; i++)
            stop = board->board[tetrimino->y + y + 1]
                [tetrimino->x + i] != tetrimino->color &&
                board->board[tetrimino->y + y + 1][tetrimino->x + i] != ' ' ?
                1 : stop;
    return (stop);
}
