/*
** EPITECH PROJECT, 2019
** run game tetris
** File description:
** tetris
*/

#include "../include/my.h"

int run_with_touch_changed(int ac, char **av, param_t *param)
{
    change_t *change = get_change(ac, av);

    if (change == NULL) {
        put_error_arg();
        return (84);
    }
    param = change_param(change, param);
    if (param == NULL)
        return (84);
    else if (param->debug == 1) {
        put_debug_mode(param);
        set_term_mode(1);
        read(0, NULL, 1);
        set_term_mode(0);
        my_putstr("\n");
    }
    run_tetris(param);
    return (0);
}

int pause_game(param_t *param, all_boards_t *all_board)
{
    if (menu_pause(param, all_board) == 1)
        return (-1);
    return (0);
}

int loop_game(param_t *param, all_boards_t *all_board, data_game_t *data_game)
{
    int nbr_loop = 0;
    int ret = 0;
    char c;

    while (1) {
        check_resize(all_board);
        refresh_pos_board(param, all_board);
        ret = add_anime_tetriminos(param, all_board, data_game);
        if (ret == 84)
            return (84);
        put_decor(all_board, param, 1);
        c = getch();
        if (get_input(c, param, all_board, data_game) == -1 && nbr_loop != 0)
            return (0);
        nbr_loop++;
        usleep(500000);
        clear_page();
    }
    return (0);
}

int run_tetris(param_t *param)
{
    all_boards_t *all_board;
    data_game_t *data_game = init_data_game(param);

    initscr();
    start_color();
    init_colors();
    curs_set(0);
    noecho();
    nodelay(stdscr, 1);
    keypad(stdscr, TRUE);
    all_board = create_all_board(param);
    if (all_board == NULL || data_game == NULL)
        return (84);
    loop_game(param, all_board, data_game);
    endwin();
    return (0);
}
