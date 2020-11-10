/*
** EPITECH PROJECT, 2019
** get utils for change
** File description:
** tetris
*/

#include "../../include/my.h"

int compare_double(char *str, char *arg)
{
    int i = 0;

    for (i = 0; arg[i]; i++)
        if (str[i] != arg[i])
            return (0);
    if (str[i])
        return (1);
    else if (my_strcmp(arg, "--debug") == 1 ||
            my_strcmp(arg, "--without-next") == 1)
        return (1);
    return (0);
}

char *get_touch_in_double(char *str)
{
    char *touch = malloc(sizeof(char) * my_strlen(str));
    int i = 0;
    int y = 0;

    if (touch == NULL)
        return (NULL);
    for (i = 0; str[i] != '='; i++);
    for (i = i + 1; str[i]; i++)
        touch[y++] = str[i];
    touch[y] = '\0';
    return (touch);
}

touch_t get_change_double(touch_t touch, char *str)
{
    touch.is = 1;
    touch.touch = get_touch_in_double(str);
    if (touch.touch == NULL || my_strlen(touch.touch) != 1)
        touch.is = -84;
    return (touch);
}

int get_nbr_row_in_arg(char *str)
{
    int i = 0;
    int y = 0;
    char *row = malloc(sizeof(char) * my_strlen(str));

    if (row == NULL)
        return (-84);
    for (i = 0; str[i] != '='; i++);
    for (i = i + 1; str[i] != ','; i++)
        row[y++] = str[i];
    row[y] = '\0';
    if (is_num(row) == 0)
        return (-84);
    return (str_to_int(row));
}

int get_nbr_col_in_arg(char *str)
{
    int i = 0;
    int y = 0;
    char *col = malloc(sizeof(char) * my_strlen(str));

    if (col == NULL)
        return (-84);
    for (i = 0; str[i] != '='; i++);
    for (i = i + 1; str[i] != ','; i++);
    for (i = i + 1; str[i]; i++)
        col[y++] = str[i];
    col[y] = '\0';
    if (is_num(col) == 0)
        return (-84);
    return (str_to_int(col));
}
