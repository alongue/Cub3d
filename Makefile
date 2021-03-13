# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alongcha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 13:18:48 by alongcha          #+#    #+#              #
#    Updated: 2021/03/12 15:57:56 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libcub.a

LIBFT	=	Libft

LIBMATH	=	Libmath

LIBFTNAME	=	libft.a

LIBMATHNAME	=	libmath.a

BITMAP	=	bitmap

PARSE	=	parsing

BSP		=	bsp

PLAYER	=	player

GNL		=	get_next_line

MAIN	=	main.c

BS	=	bonus

SRCS	=	$(MAIN)								\
			$(PARSE)/data.c						\
			$(PARSE)/player.c					\
			$(PARSE)/initmap.c					\
			$(PARSE)/newparse.c					\
			$(PARSE)/set_var_cub.c				\
			$(PARSE)/is_surrounded.c			\
			$(PARSE)/moving_side.c				\
			$(PARSE)/searching_around.c			\
			$(PARSE)/utils.c					\
			$(PARSE)/utils_nbmax.c				\
			$(PARSE)/get_info_lin.c				\
			$(PARSE)/elements.c					\
			$(PARSE)/mapcub.c					\
			$(PARSE)/resolution.c				\
			$(PARSE)/set_texture.c				\
			$(PARSE)/set_color_value.c			\
			$(PARSE)/getside.c					\
			$(PARSE)/getside2.c					\
			$(PARSE)/sort_table_y.c				\
			$(PARSE)/get_all_boundy.c			\
			$(PARSE)/get_xtreme.c				\
			$(PARSE)/xtreme_sorted.c			\
			$(PARSE)/boundaries.c				\
			$(PARSE)/outside_x.c				\
			$(PARSE)/searching_around_utils.c	\
			$(PARSE)/location_top.c				\
			$(PARSE)/location_right.c			\
			$(PARSE)/location_bot.c				\
			$(PARSE)/location_left.c			\
			$(PLAYER)/player_move.c				\
			$(PLAYER)/player_turn.c				\
			$(BITMAP)/bitmap.c					\
			$(BSP)/wall.c						\
			$(BSP)/raycast.c					\
			$(BSP)/wall_functions.c				\
			$(BSP)/object.c						\
			$(BSP)/display_ceilfloor.c			\
			$(BSP)/render_bsp.c					\
			$(BSP)/functions_tree.c				\
			$(BSP)/build_tree.c					\
			$(BSP)/parse_poly.c					\
			$(BSP)/create_poly.c				\
			$(BSP)/cond_to_create.c				\
			$(BSP)/malloc_set_child.c			\
			$(BSP)/split_polygon_func.c			\
			$(BSP)/set_best_poly_func.c			\
			$(BSP)/choose_poly.c				\
			$(GNL)/get_next_line.c				\
			$(GNL)/get_next_line_utils.c

OBJS	=	$(SRCS:.c=.o)

OBJS_B	=	$(SRCS_B:.c=.o)

AR	=	ar rc

LIB	=	ranlib

GCC	=	gcc

INC	=	-I /usr/X11/include

INCLNX	=	-I minilibx-linux

LIBFL	=	-L /usr/X11/lib -lmlx

LIBLNX	=	-lm -lmlx -lXext -lX11 -L minilibx-linux

FWFL	=	-framework OpenGL -framework AppKit

CFLAGS	=	-Wall -Wextra -Werror

DEBG	=	-fsanitize=address

VSCODE = vscode

SCREENSHOT	=	screen.bmp

all	:	$(NAME)

.c.o	:
	$(GCC) $(INCLNX) $(CFLAGS) -c $< -o $(<:.c=.o)

$(LIBFT)/.c.o	:
	make -C $(LIBFT)

$(LIBMATH)/.c.o	:
	make -C $(LIBMATH)

$(NAME)	: $(OBJS) $(LIBFT)/.c.o $(LIBMATH)/.c.o
	make -C minilibx-linux
	cp $(LIBFT)/$(LIBFTNAME) .
	cp $(LIBMATH)/$(LIBMATHNAME) .
	cp $(GNL)/*.o .
	ar -x $(LIBFTNAME)
	ar -x $(LIBMATHNAME)
	$(AR) $(NAME) $(OBJS) *.o
	$(LIB) $(NAME)
	$(GCC) $(INCLNX) $(NAME) $(LIBLNX)

$(VSCODE) : $(OBJS) $(LIBFT)/.c.o $(LIBMATH)/.c.o
	make -C minilibx-linux
	cp $(LIBFT)/$(LIBFTNAME) .
	cp $(LIBMATH)/$(LIBMATHNAME) .
	cp $(GNL)/*.o .
	ar -x $(LIBFTNAME)
	ar -x $(LIBMATHNAME)
	$(AR) $(NAME) $(OBJS) *.o
	$(LIB) $(NAME)
	$(GCC) -g $(INCLNX) $(NAME) $(LIBLNX)

exec	: $(NAME)
	./a.out $(filter-out $@, $(MAKECMDGOALS))

debug	:	$(NAME)
	$(GCC) $(INC) $(LIBFL) $(DEBG) $(NAME) $(MAIN)
	./a.out $(filter-out $@, $(MAKECMDGOALS))

clean	:
	make clean -C $(LIBFT)
	make clean -C $(LIBMATH)
	make clean -C minilibx-linux
	rm -f $(OBJS) $(OBJS_B)
	rm -f *.o

fclean	:	clean
	make fclean -C $(LIBFT)
	make fclean -C $(LIBMATH)
	make clean -C minilibx-linux
	rm -f $(SCREENSHOT)
	rm -f $(OBJS) $(OBJS_B)
	rm -f $(NAME) $(LIBFTNAME) $(LIBMATHNAME) $(BS)

fcleanmax	:	fclean
	rm -rf __.SYMDEF\ SORTED $(LIBFT)/__.SYMDEF\ SORTED __.SYMDEF
	rm -rf a.out *.dSYM prog
	rm -rf .vscode */.vscode
	rm -rf .*.swp */.*.swp
	rm -rf .DS_Store */.DS_Store
	rm -rf .dist */.dist

re	:	fclean all

reexec	:	fclean
	make exec $(filter-out $@, $(MAKECMDGOALS))

%		:
	@		:

.PHONY	:	all clean exec fcleanmax fclean re bonus vscode
