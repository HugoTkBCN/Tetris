/*
** EPITECH PROJECT, 2019
** utils terminal
** File description:
** tetris
*/

#include "../include/my.h"

void set_term_mode(int mode)
{
    static struct termios termsave;
    static struct termios term;

    if (mode == 1 || mode == 2) {
        ioctl(0, TCGETS, &term);
        ioctl(0, TCGETS, &termsave);
        term.c_lflag &= ~ECHO;
        term.c_lflag &= ~ICANON;
        term.c_cc[VMIN] = mode == 1 ? 1 : 0;
        term.c_cc[VTIME] = 0;
        ioctl(0, TCSETS, &term);
    } else
        ioctl(0, TCSETS, &termsave);
}
