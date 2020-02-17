# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alongcha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 13:18:48 by alongcha          #+#    #+#              #
#    Updated: 2020/02/17 17:50:23 by alongcha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libcub.a

LIBFT	=	Libft

LIBMATH	=	Libmath

LIBFTNAME	=	libft.a

LIBMATHNAME	=	libmath.a

PARSE	=	parsing

GNL		=	get_next_line

MAIN	=	main.c

BS	=	bonus

SRCS	=	test.c							\
			wall.c							\
			raycast.c						\
			player.c						\
			init.c							\
			wall_functions.c				\
			utils.c							\
			$(PARSE)/parse.c				\
			$(PARSE)/render_bsp.c			\
			$(PARSE)/functions_tree.c		\
			$(PARSE)/build_tree.c			\
			$(PARSE)/parse_poly.c			\
			$(PARSE)/set_var_cub.c			\
			$(PARSE)/create_poly.c			\
			$(GNL)/get_next_line.c			\
			$(GNL)/get_next_line_utils.c

OBJS	=	$(SRCS:.c=.o)

OBJS_B	=	$(SRCS_B:.c=.o)

AR	=	ar rc

LIB	=	ranlib

GCC	=	gcc

INC	=	-I /usr/X11/include

LIBFL	=	-g -L /usr/X11/lib -l mlx

FWFL	=	-framework OpenGL -framework AppKit

CFLAGS	=	-Wall -Wextra -Werror

DEBG	=	-fsanitize=address

all	:	$(NAME)

.c.o	:
	$(GCC) $(CFLAGS) -c $< -o $(<:.c=.o)

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
	rm -rf __.SYMDEF\ SORTED $(LIBFT)/__.SYMDEF\ SORTED
	rm -rf a.out *.dSYM prog
	rm -rf .vscode */.vscode
	rm -rf .*.swp */.*.swp
	rm -rf .DS_Store */.DS_Store
	rm -rf .dist */.dist

re	:	fclean all

reexec	:	fclean exec

%		:
	@		:

.PHONY	:	all clean exec fcleanmax fclean re bonus
