/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** exemple
*/

#include "include/my.h"

int main(int ac, char **av)
{
    param_t *param = get_param();

    if (param == NULL)
        return (84);
    ac = ac;
    if (ac == 1)
        run_tetris(param);
    else if (ac == 2 && my_strcmp(av[1], "--help") == 1)
        put_help(av);
    else
        if (run_with_touch_changed(ac, av, param) == 84)
            return (84);
    return (0);
}
