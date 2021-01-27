# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alongcha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 13:18:48 by alongcha          #+#    #+#              #
#    Updated: 2020/03/11 19:34:40 by alongcha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libcub.a

LIBFT	=	Libft

LIBMATH	=	Libmath

LIBFTNAME	=	libft.a

LIBMATHNAME	=	libmath.a

PARSE	=	parsing

BSP		=	bsp

GNL		=	get_next_line

MAIN	=	main.c

BS	=	bonus

SRCS	=	$(MAIN)							\
			data.c							\
			wall.c							\
			raycast.c						\
			player.c						\
			wall_functions.c				\
			player_move.c					\
			player_turn.c					\
			object.c						\
			display_ceilfloor.c				\
			$(PARSE)/newparse.c				\
			$(PARSE)/set_var_cub.c			\
			$(PARSE)/init.c					\
			$(PARSE)/is_surrounded.c		\
			$(PARSE)/moving_side.c			\
			$(PARSE)/searching_around.c		\
			$(PARSE)/utils.c				\
			$(PARSE)/utils_nbmax.c			\
			$(PARSE)/get_info_lin.c			\
			$(PARSE)/elements.c				\
			$(BSP)/render_bsp.c				\
			$(BSP)/functions_tree.c			\
			$(BSP)/build_tree.c				\
			$(BSP)/parse_poly.c				\
			$(BSP)/create_poly.c			\
			$(BSP)/cond_to_create.c			\
			$(BSP)/malloc_set_child.c		\
			$(BSP)/split_polygon_func.c		\
			$(BSP)/set_best_poly_func.c		\
			$(GNL)/get_next_line.c			\
			$(GNL)/get_next_line_utils.c

OBJS	=	$(SRCS:.c=.o)

OBJS_B	=	$(SRCS_B:.c=.o)

AR	=	ar rc

LIB	=	ranlib

GCC	=	gcc

INC	=	-I /usr/X11/include

LIBFL	=	-L /usr/X11/lib -lmlx

FWFL	=	-framework OpenGL -framework AppKit

CFLAGS	=	-Wall -Wextra -Werror

DEBG	=	-fsanitize=address

VSCODE = vscode

all	:	$(NAME)

.c.o	:
	$(GCC) $(INC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(LIBFT)/.c.o	:
	make -C $(LIBFT)

$(LIBMATH)/.c.o	:
	make -C $(LIBMATH)

$(NAME)	: $(OBJS) $(LIBFT)/.c.o $(LIBMATH)/.c.o
	cp $(LIBFT)/$(LIBFTNAME) .
	cp $(LIBMATH)/$(LIBMATHNAME) .
	cp $(GNL)/*.o .
	ar -x $(LIBFTNAME)
	ar -x $(LIBMATHNAME)
	$(AR) $(NAME) $(OBJS) *.o
	$(LIB) $(NAME)
	$(GCC) $(INC) $(LIBFL) $(FWFL) $(NAME) $(MAIN)

$(VSCODE) : $(OBJS) $(LIBFT)/.c.o $(LIBMATH)/.c.o
	cp $(LIBFT)/$(LIBFTNAME) .
	cp $(LIBMATH)/$(LIBMATHNAME) .
	cp $(GNL)/*.o .
	ar -x $(LIBFTNAME)
	ar -x $(LIBMATHNAME)
	$(AR) $(NAME) $(OBJS) *.o
	$(LIB) $(NAME)
	$(GCC) -g $(INC) $(LIBFL) $(FWFL) $(NAME) $(MAIN)

$(BS)	: $(OBJS_B)
	$(AR) $(NAME) $(OBJS_B)
	$(LIB) $(NAME)

exec	: $(NAME)
	$(GCC) $(INC) $(LIBFL) $(FWFL) $(NAME) $(MAIN)
	./a.out $(filter-out $@, $(MAKECMDGOALS))

debug	:	$(NAME)
	$(GCC) $(INC) $(LIBFL) $(FWFL) $(DEBG) $(NAME) $(MAIN)
	./a.out $(filter-out $@, $(MAKECMDGOALS))

clean	:
	make clean -C $(LIBFT)
	make clean -C $(LIBMATH)
	rm -f $(OBJS) $(OBJS_B)
	rm -f *.o

fclean	:	clean
	make fclean -C $(LIBFT)
	make fclean -C $(LIBMATH)
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
