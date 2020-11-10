/*
** EPITECH PROJECT, 2019
** menu
** File description:
** menu
*/

#include "../include/my.h"

int menu_pause(param_t *params, all_boards_t *all_board)
{
    char c = getch();

    while (1) {
        put_decor(all_board, params, 0);
        mvprintw(LINES / 2, (COLS / 2) - (my_strlen("CONTINUE [space]\n") / 2),
                "CONTINUE [space]\n");
        mvprintw(LINES / 2 + 1, (COLS / 2) - (my_strlen("EXIT [esc]") / 2),
                "EXIT [esc]");
        c = getch();
        if (c == ' ')
            return (0);
        else if (c == 27)
            return (1);
        usleep(100000);
        clear_page();
    }
}
