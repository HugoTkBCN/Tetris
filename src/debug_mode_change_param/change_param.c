/*
** EPITECH PROJECT, 2019
** change param key game
** File description:
** tetris
*/

#include "../../include/my.h"

char *check_char_key(char *str)
{
    if (str == NULL)
        return (NULL);
    else if (my_strcmp(str, " ") == 1)
        str = my_strdup(STR_SPACE);
    return (str);
}

param_t *recheck_keys(param_t *param)
{
    return ((param->next != 0 && param->next != 1) || param->level <= 0 ||
            param->size[0] <= 0 || param->size[1] <= 0 ||
            (param->debug != 1 && param->debug != 0) ||
            param->nbr_tetriminos <= 0 || param->tetriminos == NULL ||
            my_strcmp(param->keys.left, param->keys.right) == 1 ||
            my_strcmp(param->keys.left, param->keys.turn) == 1 ||
            my_strcmp(param->keys.left, param->keys.drop) == 1 ||
            my_strcmp(param->keys.left, param->keys.quit) == 1 ||
            my_strcmp(param->keys.left, param->keys.pause) == 1 ||
            my_strcmp(param->keys.right, param->keys.turn) == 1 ||
            my_strcmp(param->keys.right, param->keys.drop) == 1 ||
            my_strcmp(param->keys.right, param->keys.quit) == 1 ||
            my_strcmp(param->keys.right, param->keys.pause) == 1 ||
            my_strcmp(param->keys.turn, param->keys.drop) == 1 ||
            my_strcmp(param->keys.turn, param->keys.quit) == 1 ||
            my_strcmp(param->keys.turn, param->keys.pause) == 1 ||
            my_strcmp(param->keys.drop, param->keys.quit) == 1 ||
            my_strcmp(param->keys.drop, param->keys.pause) == 1 ||
            my_strcmp(param->keys.pause, param->keys.quit) == 1 ?
            NULL : param);
}

param_t *check_keys(param_t *param)
{
    param->keys.left = check_char_key(param->keys.left);
    param->keys.right = check_char_key(param->keys.right);
    param->keys.turn = check_char_key(param->keys.turn);
    param->keys.drop = check_char_key(param->keys.drop);
    param->keys.quit = check_char_key(param->keys.quit);
    param->keys.pause = check_char_key(param->keys.pause);
    if (param->keys.left == NULL || param->keys.right == NULL ||
        param->keys.turn == NULL || param->keys.drop == NULL ||
        param->keys.quit == NULL || param->keys.pause == NULL)
        return (NULL);
    return (recheck_keys(param));
}

param_t *change_param(change_t *change, param_t *param)
{
    param->level = change->level.is == 1 ?
        str_to_int(change->level.touch) : param->level;
    param->keys.left = change->left.is == 1 ?
        my_strdup(change->left.touch) : param->keys.left;
    param->keys.right = change->right.is == 1 ?
        my_strdup(change->right.touch) : param->keys.right;
    param->keys.turn = change->turn.is == 1 ?
        my_strdup(change->turn.touch) : param->keys.turn;
    param->keys.drop = change->drop.is == 1 ?
        my_strdup(change->drop.touch) : param->keys.drop;
    param->keys.quit = change->quit.is == 1 ?
        my_strdup(change->quit.touch) : param->keys.quit;
    param->keys.pause = change->pause.is == 1 ?
        my_strdup(change->pause.touch) : param->keys.pause;
    param->size[0] = change->size[0] == 1 ? change->size[1] : param->size[0];
    param->size[1] = change->size[0] == 1 ? change->size[2] : param->size[1];
    param->next = change->next == 1 ? 0 : param->next;
    param->debug = change->debug == 1 ? 1 : param->debug;
    return (check_keys(param));
}
