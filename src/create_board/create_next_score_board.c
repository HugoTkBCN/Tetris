/*
** EPITECH PROJECT, 2019
** create next and score board
** File description:
** tetris
*/

#include "../../include/my.h"

char **empty_board(char **board, int height, int width)
{
    int i = 0;
    int y = 0;

    height--;
    width--;
    for (i = 0; i <= height; i++) {
        for (y = 0; y <= width; y++)
            board[i][y] = ((i == 0 && y == 0) || (i == 0 && y == width) ||
            (i == height && y == 0) || (i == height && y == width)) ? 'X' :
            (i == 0 || i == height || y == 0 || y == width) ? '*' : ' ';
        board[i][y] = '\0';
    }
    board[i] = NULL;
    return (board);
}

board_t *create_next_board(param_t *param)
{
    board_t *board = malloc(sizeof(board_t *) * 2);

    if (board == NULL)
        return (NULL);
    board->nbr_lines = HEIGHT_NEXT_BOARD;
    board->nbr_cols = WIDTH_NEXT_BOARD;
    board->y = (LINES / 2) + (board->nbr_lines / 2) - POS_Y_NEXT_BOARD;
    board->x = (COLS / 2) + (((param->size[1] + 1) * 2 + 2) / 2)
        + (COLS / DISTANCE_TO_NEXT);
    return (board);
}

board_t *create_score_board(param_t *param)
{
    board_t *board = malloc(sizeof(board_t) * 2);

    if (board == NULL)
        return (NULL);
    else if ((board->board = malloc_2d_array(HEIGHT_SCORE_BOARD + 1,
            WIDTH_SCORE_BOARD + 1)) == NULL)
        return (NULL);
    board->board = empty_board(board->board, HEIGHT_SCORE_BOARD,
                                    WIDTH_SCORE_BOARD);
    board->nbr_lines = HEIGHT_SCORE_BOARD;
    board->nbr_cols = WIDTH_SCORE_BOARD;
    board->x = (COLS / 2) - ((((param->size[1] + 1) * 2) + 2) / 2) -
        (board->nbr_cols) - (COLS / DISTANCE_TO_SCORE);
    board->y = (LINES / 2) - (board->nbr_lines / 2) + POS_Y_SCORE_BOARD;
    return (board);
}
