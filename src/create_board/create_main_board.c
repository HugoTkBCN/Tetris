/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** create main board
*/

#include "../../include/my.h"

char **empty_main_board(char **board, param_t *param)
{
    int i = 0;
    int y = 0;

    for (i = 0; i <= param->size[0]; i++) {
        for (y = 0; y <= (param->size[1] + 1) * 2; y++)
            board[i][y] = ((i == 0 && y == 0) ||
            (i == 0 && y == (param->size[1] + 1) * 2) ||
            (i == param->size[0] && y == 0) || (i == param->size[0] &&
            y == (param->size[1] + 1) * 2)) ? '0' : (i == 0 ||
            i == param->size[0] || y == 0 ||
            y == (param->size[1] + 1) * 2) ? '+' : ' ';
        board[i][y] = '\0';
    }
    board[i] = NULL;
    return (board);
}

board_t *create_main_board(param_t *param)
{
    board_t *board = malloc(sizeof(board_t) * 2);

    if (board == NULL)
        return (NULL);
    else if ((board->board = malloc_2d_array(param->size[0] + 1,
            (param->size[1] + 1) * 2 + 2)) == NULL)
        return (NULL);
    board->board = empty_main_board(board->board, param);
    board->nbr_lines = param->size[0] + 1;
    board->nbr_cols = ((param->size[1] + 1) * 2) + 1;
    board->x = (COLS / 2) - (board->nbr_cols / 2);
    board->y = (LINES / 2) - (board->nbr_lines / 2) + (POS_Y_MAIN_BOARD / 10);
    return (board);
}
