##
## EPITECH PROJECT, 2018
## makefile
## File description:
## .o
##

SRC	=	utils/my_putchar.c	\
		utils/my_putstr.c	\
		utils/my_put_nbr.c	\
		utils/my_strlen.c	\
		utils/my_strdup.c	\
		utils/my_strcpy.c	\
		utils/mem_alloc.c	\
		utils/convert.c	\
		utils/my_revstr.c	\
		utils/my_strcmp.c	\
		utils/len_line.c	\
		utils/my_arraydup.c	\
		utils/malloc_2d_array.c	\
		src/add_anime_tetriminos.c	\
		src/check_in_game.c	\
		src/init.c	\
		src/movements.c	\
		src/put_game.c	\
		src/run_game.c	\
		src/utils_term.c	\
		src/put_help_message.c	\
		src/print_ncurses.c	\
		src/input.c	\
		src/next_board.c	\
		src/debug_mode_change_param/change_param.c	\
		src/debug_mode_change_param/get_double_sep_change.c	\
		src/debug_mode_change_param/get_simple_sep_change.c	\
		src/debug_mode_change_param/get_utils_for_change.c	\
		src/debug_mode_change_param/is.c	\
		src/debug_mode_change_param/run_change_param.c	\
		src/debug_mode_change_param/get_tetriminos_file_name.c	\
		src/debug_mode_change_param/get_debug_mode_2.c	\
		src/debug_mode_change_param/get_param.c	\
		src/debug_mode_change_param/get_debug_mode.c	\
		src/debug_mode_change_param/put_debug_mode.c	\
		src/debug_mode_change_param/put_tetriminos_info_debug_mode.c	\
		src/debug_mode_change_param/check_debug_mode.c	\
		src/create_board/create_boards.c	\
		src/create_board/create_next_score_board.c	\
		src/create_board/create_main_board.c	\
		src/menu.c	\
		src/verif_moves.c

NAME	=	tetris

OBJ	=	$(SRC:.c=.o)

FLAGS =	-Wall -Werror

LIB =	-lcurses

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) main.c $(OBJ) $(LIB) $(FLAGS)

clean:
	rm -rf $(OBJ)
fclean:		clean
	rm -rf $(NAME)

re:	fclean all
