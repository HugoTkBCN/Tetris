/*
** EPITECH PROJECT, 2019
** get with simple sep
** File description:
** tetris
*/

#include "../../include/my.h"

int get_simple(char **av, int i, change_t *change)
{
    if (my_strcmp(S_FLAG_NEXT, av[i]) == 1) {
        change->next = 1;
        return (i);
    } else if (my_strcmp(S_FLAG_DEBUG, av[i]) == 1) {
        change->debug = 1;
        return (i);
    }
    i = i;
    if (!av[i + 1])
        return (-84);
    else if (my_strcmp(S_FLAG_LEVEL, av[i]) == 1) {
        change->level.is = 1;
        change->level.touch = my_strdup(av[i + 1]);
        if (is_num(change->level.touch) == 0 ||
            str_to_int(change->level.touch) <= 0)
            return (-84);
        return (i + 1);
    }
    return (get_simple_2(av, i, change));
}

int get_simple_2(char **av, int i, change_t *change)
{
    if (my_strlen(av[i + 1]) != 1)
            return (-84);
    else if (my_strcmp(S_FLAG_LEFT, av[i]) == 1) {
        change->left.is = 1;
        change->left.touch = my_strdup(av[i + 1]);
        return (i + 1);
    }
    i = i;
    if (my_strcmp(S_FLAG_RIGHT, av[i]) == 1) {
        change->right.is = 1;
        change->right.touch = my_strdup(av[i + 1]);
        return (i + 1);
    } else if (my_strcmp(S_FLAG_TURN, av[i]) == 1) {
        change->turn.is = 1;
        change->turn.touch = my_strdup(av[i + 1]);
        return (i + 1);
    }
    return (get_simple_3(av, i, change));
}

int get_simple_3(char **av, int i, change_t *change)
{
    if (my_strcmp(S_FLAG_DROP, av[i]) == 1) {
        change->drop.is = 1;
        change->drop.touch = my_strdup(av[i + 1]);
        return (i + 1);
    } else if (my_strcmp(S_FLAG_QUIT, av[i]) == 1) {
        change->quit.is = 1;
        change->quit.touch = my_strdup(av[i + 1]);
        return (i + 1);
    }
    i = i;
    if (my_strcmp(S_FLAG_PAUSE, av[i]) == 1) {
        change->pause.is = 1;
        change->pause.touch = my_strdup(av[i + 1]);
    }
    return (i + 1);
}
