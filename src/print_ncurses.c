/*
** EPITECH PROJECT, 2019
** print
** File description:
** tetris
*/

#include "../include/my.h"

void clear_page(void)
{
    clear();
    refresh();
}

int is_color(char c)
{
    for (int i = 0; i <= NBR_COLOR_MAX; i++)
        if (c == i)
            return (1);
    return (0);
}

void put_elem(char **elem, float x_y[2], int nbr_lines, int color)
{
    int i = 0;
    int x = x_y[0];
    int y = x_y[1];
    int save_x = x;

    for (i = 0; elem[i]; i++);
    for (int f = i - 1; f >= 0; f--) {
        x = save_x;
        for (int c = 0; c < my_strlen(elem[f]); c++) {
            attron(COLOR_PAIR(is_color(elem[f][c]) ? elem[f][c] : color));
            is_color(elem[f][c]) ? mvprintw(y + nbr_lines - 1, x++, "*") :
                mvprintw(y + nbr_lines - 1, x++, "%c", elem[f][c]);
            attroff(COLOR_PAIR(is_color(elem[f][c]) ? elem[f][c] : color));
        }
        nbr_lines--;
    }
}
