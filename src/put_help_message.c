/*
** EPITECH PROJECT, 2019
** put help and message
** File description:
** tetris
*/

#include "../include/my.h"

void put_help(char **av)
{
    my_putstr("Usage:  ");
    my_putstr(av[0]);
    my_putstr(" [options]\nOptions:\n --help               Display this help");
    my_putstr("\n -L --level={num}     Start Tetris at level num (def: 1)\n");
    my_putstr(" -l --key-left={K}    Move the tetrimino LEFT using the K key");
    my_putstr(" (def: left arrow)\n");
    my_putstr(" -r --key-right={K}   Move the tetrimino RIGHT using the K key");
    my_putstr(" (def: right arrow)\n");
    my_putstr(" -t --key-turn={K}    TURN the tetrimino clockwise 90d using");
    my_putstr(" the K key (def: toparrow)\n");
    my_putstr(" -d --key-drop={K}    DROP the tetrimino using the K key");
    my_putstr(" (def: down arrow)\n");
    my_putstr(" -q --key-quit={K}    QUIT the game using the");
    my_putstr(" K key (def: ‘q’ key)\n");
    my_putstr(" -p --key-pause={K}   PAUSE/RESTART the game using");
    my_putstr(" the K key (def: space bar)\n");
    my_putstr(" --map-size={row,col} Set the numbers of rows ");
    my_putstr("and columns of the map (def: 20,10)\n");
    my_putstr(" -w --without-next    Hide next tetrimino (def: false)\n");
    my_putstr(" -D --debug\t      Debug mode (def: false)\n");
}

void put_error_arg(void)
{
    my_putstr("Bad argument(s), for more information use :\n");
    my_putstr("\t./tetris --help\n");
}
