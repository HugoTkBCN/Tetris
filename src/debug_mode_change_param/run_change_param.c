/*
** EPITECH PROJECT, 2019
** run change param
** File description:
** tetris
*/

#include "../../include/my.h"

change_t *init_change(change_t *change)
{
    change->level.is = 0;
    change->left.is = 0;
    change->right.is = 0;
    change->turn.is = 0;
    change->drop.is = 0;
    change->quit.is = 0;
    change->pause.is = 0;
    change->size[0] = 0;
    change->next = 0;
    change->debug = 0;
    return (change);
}

change_t *get_change(int ac, char **av)
{
    change_t *change = malloc(sizeof(change_t) * 2);
    int ret;

    if (change == NULL)
        return (NULL);
    change = init_change(change);
    for (int i = 1; i < ac; i++) {
        if ((ret = is_param(av[i])) != 0) {
            if (ret == 2)
                i = get_double(av, i, change);
            else if (ret == 1)
                i = get_simple(av, i, change);
        }
        if (i == -84 || ret == 0) {
            return (NULL);
        }
    }
    return (change);
}
