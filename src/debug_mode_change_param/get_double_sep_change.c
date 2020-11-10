/*
** EPITECH PROJECT, 2019
** get double sep change
** File description:
** tetris
*/

#include "../../include/my.h"

int get_double(char **av, int i, change_t *change)
{
    if (compare_double(av[i], L_FLAG_LEVEL)) {
        change->level.is = 1;
        change->level.touch = get_touch_in_double(av[i]);
        if (change->level.touch == NULL || is_num(change->level.touch) == 0
            || str_to_int(change->level.touch) <= 0)
            return (-84);
        return (i);
    } else if (compare_double(av[i], L_FLAG_LEFT)) {
        change->left = get_change_double(change->left, av[i]);
        if (change->left.is == -84)
            return (-84);
        return (i);
    }
    return (get_double_2(av, i, change));
}

int get_double_2(char **av, int i, change_t *change)
{
    if (compare_double(av[i], L_FLAG_RIGHT)) {
        change->right = get_change_double(change->right, av[i]);
        if (change->right.is == -84)
            return (-84);
        return (i);
    } else if (compare_double(av[i], L_FLAG_TURN)) {
        change->turn = get_change_double(change->turn, av[i]);
        if (change->turn.is == -84)
            return (-84);
        return (i);
    }
    i = i;
    if (compare_double(av[i], L_FLAG_DROP)) {
        change->drop = get_change_double(change->drop, av[i]);
        if (change->drop.is == -84)
            return (-84);
        return (i);
    }
    return (get_double_3(av, i, change));
}

int get_double_3(char **av, int i, change_t *change)
{
    if (compare_double(av[i], L_FLAG_QUIT)) {
        change->quit = get_change_double(change->quit, av[i]);
        if (change->quit.is == -84)
            return (-84);
        return (i);
    } else if (compare_double(av[i], L_FLAG_PAUSE)) {
        change->pause = get_change_double(change->pause, av[i]);
        if (change->pause.is == -84)
            return (-84);
        return (i);
    }
    i = i;
    if (compare_double(av[i], L_FLAG_NEXT)) {
        change->next = 1;
        return (i);
    } else if (compare_double(av[i], L_FLAG_DEBUG)) {
        change->debug = 1;
        return (i);
    }
    return (get_double_4(av, i, change));
}

int get_double_4(char **av, int i, change_t *change)
{
    if (compare_double(av[i], L_FLAG_SIZE)) {
        change->size[0] = 1;
        if (is_separator(av[i]) == 0)
            return (-84);
        change->size[1] = get_nbr_row_in_arg(av[i]);
        change->size[2] = get_nbr_col_in_arg(av[i]);
        if (change->size[1] == -84 || change->size[2] == -84 ||
            change->size[1] <= 0 || change->size[2] <= 0)
            return (-84);
    }
    return (i);
}
