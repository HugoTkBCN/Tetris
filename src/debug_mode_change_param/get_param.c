/*
** EPITECH PROJECT, 2019
** get_param
** File description:
** tetris
*/

#include "../../include/my.h"

keys_t get_keys(void)
{
    keys_t keys;

    keys.left = my_strdup(DEFAULT_LEFT);
    keys.right = my_strdup(DEFAULT_RIGHT);
    keys.turn = my_strdup(DEFAULT_TURN);
    keys.drop = my_strdup(DEFAULT_DROP);
    keys.quit = my_strdup(DEFAULT_QUIT);
    keys.pause = my_strdup(DEFAULT_PAUSE);
    return (keys);
}

param_t *get_param(void)
{
    char **files_name = get_name_files_in_dir(PATH_TETRIMINOS);
    param_t *param = malloc(sizeof(param_t) * 2);

    if (files_name == NULL || param == NULL)
        return (NULL);
    param->keys = get_keys();
    param->next = DEFAULT_NEXT;
    param->level = DEFAULT_LEVEL;
    param->size[0] = DEFAULT_SIZE[0];
    param->size[1] = DEFAULT_SIZE[1];
    param->debug = DEFAULT_DEBUG;
    param->nbr_tetriminos = get_nbr_tetriminos(files_name);
    param->tetriminos = get_tetriminos_info(files_name, param->nbr_tetriminos);
    if (param->tetriminos == NULL)
        return (NULL);
    return (param);
}
