/*
** EPITECH PROJECT, 2019
** create boards
** File description:
** tetris
*/

#include "../../include/my.h"

all_boards_t *refresh_pos_board(param_t *param, all_boards_t *all_board)
{
    all_board->main_board->x = (COLS / 2) -
        (all_board->main_board->nbr_cols / 2);
    all_board->main_board->y = (LINES / 2) -
        (all_board->main_board->nbr_lines / 2) + (POS_Y_MAIN_BOARD / 10);
    all_board->score_board->x = (COLS / 2) -
        ((((param->size[1] + 1) * 2) + 2) / 2) -
        (all_board->score_board->nbr_cols) - (COLS / DISTANCE_TO_SCORE);
    all_board->score_board->y = (LINES / 2) - (all_board->score_board->nbr_lines
                                                / 2) + POS_Y_SCORE_BOARD;
    all_board->next_board->x = (COLS / 2) + (((param->size[1] + 1) * 2 + 2) / 2)
        + (COLS / DISTANCE_TO_NEXT);
    all_board->next_board->y =  (LINES / 2) +
        (all_board->next_board->nbr_lines / 2) - POS_Y_NEXT_BOARD;
    return (all_board);
}

void add_line(char *line, char *to_add)
{
    int y = 0;

    for (int i = 1; to_add[y]; i++) {
        if (i >= 2 && i <= my_strlen(to_add) + 1)
            line[i] = to_add[y++];
    }
}

board_t *write_in_score_board(board_t *board)
{
    add_line(board->board[LINE_HIGHT_SCORE + 1], "Hight Score :");
    add_line(board->board[LINE_SCORE + 1], "Score :");
    add_line(board->board[LINE_LINES + 1], "Lines :");
    add_line(board->board[LINE_LEVEL + 1], "Level :");
    add_line(board->board[LINE_TIMER + 1], "Timer :");
    return (board);
}

all_boards_t *create_all_board(param_t *param)
{
    all_boards_t *all_board = malloc(sizeof(all_boards_t) * 2);

    if (all_board == NULL)
        return (NULL);
    all_board->main_board = create_main_board(param);
    if (all_board->main_board == NULL)
        return (NULL);
    all_board->score_board = create_score_board(param);
    if (all_board->score_board == NULL)
        return (NULL);
    all_board->next_board = create_next_board(param);
    if (all_board->next_board == NULL)
        return (NULL);
    all_board->score_board = write_in_score_board(all_board->score_board);
    return (all_board);
}
