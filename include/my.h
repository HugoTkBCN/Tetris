/*
** EPITECH PROJECT, 2019
** include
** File description:
** exemple
*/

#ifndef MY_H_
#define MY_H_

#define NBR_COLOR_MAX 7
#define ERROR_RESIZE_STR "Resize the window !"
#define POS_Y_MAIN_BOARD 50
#define LINE_HIGHT_SCORE 1
#define LINE_SCORE 2
#define LINE_LINES 4
#define LINE_LEVEL 5
#define LINE_TIMER 7
#define HEIGHT_SCORE_BOARD 11
#define WIDTH_SCORE_BOARD 25
#define DISTANCE_TO_SCORE 23
#define POS_Y_SCORE_BOARD 10
#define HEIGHT_NEXT_BOARD 7
#define WIDTH_NEXT_BOARD 12
#define DISTANCE_TO_NEXT 23
#define POS_Y_NEXT_BOARD 4
#define STR_SPACE "(space)"
#define PATH_TETRIMINOS "tetriminos/"
#define DEFAULT_LEFT "^EOD"
#define DEFAULT_RIGHT "^EOC"
#define DEFAULT_TURN "^EOA"
#define DEFAULT_DROP "^EOB"
#define DEFAULT_QUIT "q"
#define DEFAULT_PAUSE "(space)"
#define DEFAULT_NEXT 1
#define DEFAULT_LEVEL 1
#define DEFAULT_SIZE (int[2]){20, 10}
#define DEFAULT_DEBUG 0
#define S_FLAG_LEVEL "-L"
#define S_FLAG_LEFT "-l"
#define S_FLAG_RIGHT "-r"
#define S_FLAG_TURN "-t"
#define S_FLAG_DROP "-d"
#define S_FLAG_QUIT "-q"
#define S_FLAG_PAUSE "-p"
#define S_FLAG_NEXT "-w"
#define S_FLAG_DEBUG "-D"
#define L_FLAG_LEVEL "--level="
#define L_FLAG_LEFT "--key-left="
#define L_FLAG_RIGHT "--key-right="
#define L_FLAG_TURN "--key-turn="
#define L_FLAG_DROP "--key-drop="
#define L_FLAG_QUIT "--key-quit="
#define L_FLAG_PAUSE "--key-pause="
#define L_FLAG_NEXT "--without-next"
#define L_FLAG_DEBUG "--debug"
#define L_FLAG_SIZE "--map-size="
#define ARG (char *[20]){"-L", "--level=", "-l", "--key-left=", "-r", \
            "--key-right=", "-t", "--key-turn=", "-d", "--key-drop=", "-q", \
            "--key-quit=", "-p", "--key-pause=", "--map-size=", "-w", \
            "--without-next", "-D", "--debug", NULL}
#define LEN_SPACE 2
#define T (char *[10]){                          \
        "*************",                        \
            "      *      ",                    \
            "      *      ",                    \
            "      *      ",                    \
            "      *      ",                    \
            "      *      ",                    \
            "      *      ",                    \
            "      *      ",                    \
            "      *      ",                    \
            NULL}
#define LEN_T 13
#define E (char *[10]){                                                  \
        "*********",                                                    \
            "*        ",                                                \
            "*        ",                                                \
            "*        ",                                                \
            "*******  ",                                                \
            "*        ",                                                \
            "*        ",                                                \
            "*        ",                                                \
            "*********",                                                \
            NULL}
#define LEN_E 9
#define R (char *[10]){                           \
        "***********",                           \
            "*         *",                       \
            "*         *",                       \
            "*         *",                       \
            "***********",                       \
            "*      *   ",                       \
            "*       *  ",                       \
            "*        * ",                       \
            "*         *",                       \
            NULL}
#define LEN_R 11
#define I (char *[10]){                          \
        "****",                                 \
            " **",                              \
            " **",                              \
            " **",                              \
            " **",                              \
            " **",                              \
            " **",                              \
            " **",                              \
            "****",                             \
            NULL}
#define LEN_I 4
#define S (char *[10]){                                                 \
        "*************",                                                \
            "*            ",                                            \
            "*            ",                                            \
            "*            ",                                            \
            "*************",                                            \
            "            *",                                            \
            "            *",                                            \
            "            *",                                            \
            "*************",                                            \
            NULL}
#define LEN_S 13

#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <ncurses.h>
#include <curses.h>
#include <time.h>

typedef struct board_s {
    char **board;
    int nbr_lines;
    int nbr_cols;
    float x;
    float y;
} board_t;

typedef struct all_boards_s {
    board_t *main_board;
    board_t *score_board;
    board_t *next_board;
} all_boards_t;

typedef struct touch_s {
    int is;
    char *touch;
} touch_t;

typedef struct change_s {
    touch_t level;
    touch_t left;
    touch_t right;
    touch_t turn;
    touch_t drop;
    touch_t quit;
    touch_t pause;
    int size[3];
    int next;
    int debug;
} change_t;

typedef struct tetrimino_s {
    int good;
    int x;
    int y;
    char *name;
    int height;
    int width;
    int save_height;
    int save_width;
    int color;
    char **save_shape;
    char **shape;
} tetrimino_t;

typedef struct keys_s {
    char *left;
    char *right;
    char *turn;
    char *drop;
    char *quit;
    char *pause;
} keys_t;

typedef struct param_s {
    keys_t keys;
    int next;
    int level;
    int size[2];
    int debug;
    int nbr_tetriminos;
    tetrimino_t *tetriminos;
}param_t;

typedef struct data_game_s {
    int is_falling;
    int is_line_empty;
    int next_tetriminos;
    int actual_tetriminos;
} data_game_t;

int len_line(char **);
void my_putchar(char c);
int my_put_nbr(int nb);
void my_putstr(char const *str);
int my_strlen(char const *);
char *my_strdup(char *src);
char *my_strcpy(char *dest, char *src);
int check_who_is_first(char *str_1, char *str_2);
char **loop_alpha_order(char **array, char a, char b, char *temp);
char **order_letter(char **array);
int get_nbr_file_in_dir(char *filepath);
char **get_name_files_in_dir(char *filepath);
char *mem_alloc(char const *a, char const *b);
int str_to_int(char *nbr);
char *int_to_str(int nbr);
int char_to_int(char nbr);
char int_to_char(int nbr);
char *my_revstr(char *str);
int get_nbr_line(char *filepath);
char **get_tetriminos(char *filepath);
int get_real_width(char **array);
int get_real_height(char **array);
int get_color_tetrimino(char **tetrimino);
int get_width_tetrimino(char **tetrimino);
int get_height_tetrimino(char **tetrimino);
char **get_shape_tetrimino(char **tetrimino);
int get_nbr_tetriminos(char **files_name);
char *get_name_tetrimino(char *long_name);
int check_shape(char **shape, int height, int width);
int check_tetriminos(tetrimino_t tetrimino);
tetrimino_t convert_to_struct(char **array);
void put_error(tetrimino_t tetrimino);
void print_tetriminos_info(tetrimino_t tetrimino);
tetrimino_t *get_tetriminos_info(char **files_name, int nbr_tetriminos);
keys_t get_keys(void);
param_t *get_param(void);
void put_keys(keys_t keys);
void put_param(param_t *param);
void put_info_tetriminos(param_t *param);
void put_debug_mode(param_t *param);
int my_strcmp(char *str1, char *str2);
void set_term_mode(int mode);
int is_num (char *str);
int is_param(char *str);
int is_separator(char *str);
char *get_touch_in_double(char *str);
touch_t get_change_double(touch_t touch, char *str);
int get_nbr_row_in_arg(char *str);
int get_nbr_col_in_arg(char *str);
change_t *init_change(change_t *change);
int run_tetris(param_t *param);
int run_with_touch_changed(int ac, char **av, param_t *param);
int compare_double(char *str, char *arg);
change_t *get_change(int ac, char **av);
int get_simple(char **av, int i, change_t *change);
int get_simple_2(char **av, int i, change_t *change);
int get_simple_3(char **av, int i, change_t *change);
int get_double(char **av, int i, change_t *change);
int get_double_2(char **av, int i, change_t *change);
int get_double_3(char **av, int i, change_t *change);
int get_double_4(char **av, int i, change_t *change);
void put_help(char **);
void put_error_arg(void);
param_t *change_param(change_t *change, param_t *param);
void clear_page(void);
void put_elem(char **elem, float x_y[2], int nbr_lines, int);
char **malloc_2d_array(int nbr_lines, int nbr_cols);
char **empty_main_board(char **board, param_t *param);
board_t *create_main_board(param_t *param);
all_boards_t *create_all_board(param_t *param);
all_boards_t *refresh_pos_board(param_t *, all_boards_t *);
char **empty_board(char **board, int height, int width);
board_t *create_next_board(param_t *param);
board_t *create_score_board(param_t *param);
void init_colors(void);
data_game_t *init_data_game(param_t *);
void put_boards(all_boards_t *all_board, param_t *param);
void put_decor(all_boards_t *all_board, param_t *param, int board);
void check_resize(all_boards_t *all_board);
int add_anime_tetriminos(param_t *, all_boards_t *, data_game_t *);
int menu_pause(param_t *params, all_boards_t *all_board);
int add_tetriminos_to_next_board(board_t *, tetrimino_t);
void move_tetriminos_in_board(board_t *, tetrimino_t *, data_game_t *);
int verif_down(tetrimino_t *, board_t *);
int verif_left(tetrimino_t *, board_t *);
int verif_right(tetrimino_t *, board_t *);
int same_key(char c, char *touch);
int get_input(char, param_t *, all_boards_t *, data_game_t *);
void go_left(board_t *, param_t *, data_game_t *, tetrimino_t *);
void go_right(board_t *, param_t *, data_game_t *, tetrimino_t *);
void turn(board_t *, param_t *, data_game_t *, tetrimino_t *);
void drop(board_t *, param_t *, data_game_t *, tetrimino_t *);
int pause_game(param_t *, all_boards_t *);
void add_tetriminos_to_main_board(board_t *, tetrimino_t, data_game_t *);
char **my_array_dup(char **array);

#endif /* !MY_H_ */
