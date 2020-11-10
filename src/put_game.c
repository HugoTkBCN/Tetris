/*
** EPITECH PROJECT, 2019
** put game
** File description:
** tetris
*/

#include "../include/my.h"

void put_boards(all_boards_t *all_board, param_t *param)
{
    put_elem(all_board->main_board->board, (float[2]){all_board->main_board->x,
    all_board->main_board->y}, all_board->main_board->nbr_lines, 7);
    put_elem(all_board->score_board->board,
    (float[2]){all_board->score_board->x, all_board->score_board->y},
    all_board->score_board->nbr_lines, 7);
    param->next == 1 ? put_elem(all_board->next_board->board,
    (float[2]){all_board->next_board->x, all_board->next_board->y},
    all_board->next_board->nbr_lines, 7) : 0;
}

void put_decor(all_boards_t *all_board, param_t *param, int board)
{
    int tot_len = LEN_T + LEN_E + LEN_T + LEN_R +
        LEN_I + LEN_S + (LEN_SPACE * 6);

    srand(time(0));
    put_elem(T, (float[2]){(COLS / 2) - (tot_len / 2), 0}, len_line(T),
    rand() % NBR_COLOR_MAX);
    put_elem(E, (float[2]){(COLS / 2) - (tot_len / 2) + LEN_T + LEN_SPACE, 0},
    len_line(E), rand() % NBR_COLOR_MAX);
    put_elem(T, (float[2]){(COLS / 2) - (tot_len / 2) + LEN_T +
    LEN_E + (LEN_SPACE * 2), 0}, len_line(T), rand() % NBR_COLOR_MAX);
    put_elem(R, (float[2]){(COLS / 2) - (tot_len / 2) + LEN_T +
    LEN_E + LEN_T + (LEN_SPACE * 3), 0}, len_line(R), rand() % NBR_COLOR_MAX);
    put_elem(I, (float[2]){(COLS / 2) - (tot_len / 2) + LEN_T + LEN_E + LEN_T +
    LEN_R + (LEN_SPACE * 4), 0}, len_line(I), rand() % NBR_COLOR_MAX);
    put_elem(S, (float[2]){(COLS / 2) - (tot_len / 2) + LEN_T + LEN_E +
    LEN_T + LEN_R + LEN_I + LEN_SPACE * 5, 0}, len_line(S),
    rand() % NBR_COLOR_MAX);
    board == 1 ? put_boards(all_board, param) : 0;
}
