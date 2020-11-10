/*
** EPITECH PROJECT, 2019
** put debug mode
** File description:
** tetris
*/

#include "../../include/my.h"

void put_keys(keys_t keys)
{
    my_putstr("Key Left :  ");
    my_putstr(keys.left);
    my_putstr("\n");
    my_putstr("Key Rigth :  ");
    my_putstr(keys.right);
    my_putstr("\n");
    my_putstr("Key Turn :  ");
    my_putstr(keys.turn);
    my_putstr("\n");
    my_putstr("Key Drop :  ");
    my_putstr(keys.drop);
    my_putstr("\n");
    my_putstr("Key Quit :  ");
    my_putstr(keys.quit);
    my_putstr("\n");
    my_putstr("Key Pause :  ");
    my_putstr(keys.pause);
    my_putstr("\n");
}

void put_param(param_t *param)
{
    my_putstr("Next :\t");
    param->next == 1 ? my_putstr("Yes\n") : my_putstr("No\n");
    my_putstr("Level :\t");
    my_put_nbr(param->level);
    my_putstr("\n");
    my_putstr("Size :\t");
    my_put_nbr(param->size[0]);
    my_putstr("*");
    my_put_nbr(param->size[1]);
    my_putstr("\n");
}

void put_info_tetriminos(param_t *param)
{
    my_putstr("Tetriminos : ");
    my_put_nbr(param->nbr_tetriminos);
    my_putstr("\n");
    for (int i = 0; i < param->nbr_tetriminos; i++) {
        if (check_tetriminos(param->tetriminos[i]) == 84) {
            param->tetriminos[i].good = 0;
            put_error(param->tetriminos[i]);
        } else {
            param->tetriminos[i].good = 1;
            print_tetriminos_info(param->tetriminos[i]);
        }
    }
}

void put_debug_mode(param_t *param)
{
    my_putstr("*** DEBUG MODE ***\n");
    put_keys(param->keys);
    put_param(param);
    put_info_tetriminos(param);
    my_putstr("Press any key to start Tetris");
}
