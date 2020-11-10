/*
** EPITECH PROJECT, 2019
** next tetriminos
** File description:
** tetris
*/

#include "../include/my.h"

void loop_do_next_board(int y, tetrimino_t tetrimino, board_t *next_board)
{
    int i = 0;

    for (i = 0; i <= tetrimino.width + 3; i++)
        if ((y == 0 && i == 0) || (y == 0 && i == tetrimino.width + 3) ||
            (y == tetrimino.height + 3 && i == 0) ||
            (y == tetrimino.height + 3 && i == tetrimino.width + 3))
            next_board->board[y][i] = 'X';
        else if (y == 0 || i == 0 || y == tetrimino.height + 3 ||
                i == tetrimino.width + 3)
            next_board->board[y][i] = '*';
        else
            next_board->board[y][i] = ' ';
    next_board->board[y][i] = '\0';
}

int add_tetriminos_to_next_board(board_t *next_board, tetrimino_t tetrimino)
{
    int y = 0;

    next_board->board = malloc(sizeof(char *) * (tetrimino.height + 5));
    if (next_board->board == NULL)
        return (84);
    for (int c = 0; c < tetrimino.height + 5; c++)
        if ((next_board->board[c] = malloc(sizeof(char) *
                                            (tetrimino.width + 5))) == NULL)
            return (84);
    for (y = 0; y <= tetrimino.height + 3; y++)
        loop_do_next_board(y, tetrimino, next_board);
    next_board->board[y] = NULL;
    for (y = 0; tetrimino.shape[y]; y++)
        for (int i = 0; tetrimino.shape[y][i]; i++)
            next_board->board[y + 2][i + 2] = tetrimino.shape[y][i] == '*' ?
                tetrimino.color : tetrimino.shape[y][i];
    return (0);
}
