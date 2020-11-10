/*
** EPITECH PROJECT, 2019
** input
** File description:
** tetris
*/

#include "../include/my.h"

int same_key(char c, char *touch)
{
    char touch_c;

    if (my_strcmp(touch, STR_SPACE) == 1)
        touch_c = ' ';
    else if (my_strcmp(touch, DEFAULT_DROP) == 1)
        touch_c = 2;
    c = c;
    if (my_strcmp(touch, DEFAULT_TURN) == 1)
        touch_c = 3;
    else if (my_strcmp(touch, DEFAULT_LEFT) == 1)
        touch_c = 4;
    c = c;
    if (my_strcmp(touch, DEFAULT_RIGHT) == 1)
        touch_c = 5;
    c = c;
    if (c == touch[0] || c == touch_c)
        return (1);
    return (0);
}

int get_input(char c, param_t *param, all_boards_t *all_board,
            data_game_t *data_game)
{
    if (same_key(c, param->keys.left) == 1)
        go_left(all_board->main_board, param, data_game,
        &param->tetriminos[data_game->actual_tetriminos]);
    else if (same_key(c, param->keys.right) == 1)
        go_right(all_board->main_board, param, data_game,
        &param->tetriminos[data_game->actual_tetriminos]);
    c = c;
    if (same_key(c, param->keys.turn) == 1)
        turn(all_board->main_board, param, data_game,
        &param->tetriminos[data_game->actual_tetriminos]);
    else if (same_key(c, param->keys.drop) == 1)
        drop(all_board->main_board, param, data_game,
        &param->tetriminos[data_game->actual_tetriminos]);
    c = c;
    if (same_key(c, param->keys.quit) == 1)
        return (-1);
    else if (same_key(c, param->keys.pause) == 1)
        return (pause_game(param, all_board));
    return (0);
}
