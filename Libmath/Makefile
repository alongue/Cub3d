# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alongcha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 13:18:48 by alongcha          #+#    #+#              #
#    Updated: 2020/03/10 11:24:33 by alongcha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libmath.a

SRCS	=	ft_abs.c				\
			do_intersect.c			\
			get_normal.c			\
			onsegment.c				\
			min.c					\
			max.c					\
			is_colinear.c			\
			orientation.c			\
			join_segment.c			\
			get_segment.c			\
			get_point.c				\
			dup_segment.c			\
			dup_point.c				\
			is_pair.c				\
			is_same_segment.c		\
			get_segmenti.c			\
			translate_segment.c		\
			split_segment_inc.c		\
			split_segment_exc.c		\
			set_point_on_segx.c		\
			set_point_on_segy.c		\
			dup_normal.c			\
			get_next_point.c		\
			get_prev_point.c		\
			get_extremity.c			\
			translate_point.c		\
			translate_segment.c		\
			to_rad.c				\
			get_length.c			\
			get_lengthp.c			\
			to_deg.c				\
			set_btwn_zero_twopi.c	\
			set_btwn_minpi_pi.c		\
			set_btwn_minpitw_pitw.c	

OBJS	=	$(SRCS:.c=.o)

HEAD	=	libmath.h

AR	=	ar rc

LIB	=	ranlib

GCC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror

all	:	$(NAME)

.c.o	:
	$(GCC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME)	: $(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(LIB) $(NAME)

$(BS)	: $(OBJS_B)
	$(AR) $(NAME) $(OBJS_B)
	$(LIB) $(NAME)

clean	:
	rm -f $(OBJS) $(OBJS_B)

fclean	:	clean
	rm -f $(NAME) $(BS)

re	:	fclean all

.PHONY	:	all clean fclean re bonus
