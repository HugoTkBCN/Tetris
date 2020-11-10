/*
** EPITECH PROJECT, 2019
** check in game
** File description:
** tetris
*/

#include "../include/my.h"

void check_resize(all_boards_t *all_board)
{
    int tot_line = all_board->main_board->nbr_lines + len_line(T);
    int tot_col = (all_board->main_board->nbr_cols + 1) +
        (all_board->score_board->nbr_cols + 1) +
        (all_board->next_board->nbr_cols + 1) +
        (((COLS / DISTANCE_TO_SCORE) + 1) * 2) +
        (((COLS / DISTANCE_TO_NEXT) + 1) * 2) + 1;
    float len_error = my_strlen(ERROR_RESIZE_STR);

    while (LINES < tot_line || COLS < tot_col) {
        clear();
        mvprintw((LINES / 2), (COLS / 2) - (len_error / 2), ERROR_RESIZE_STR);
        refresh();
    }
}
