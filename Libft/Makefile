# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alongcha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 13:18:48 by alongcha          #+#    #+#              #
#    Updated: 2020/03/10 12:21:36 by alongcha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

BS	=	bonus

SRCS	=	ft_atoi.c		\
		ft_isalpha.c		\
		ft_itoa.c			\
		ft_memcpy.c			\
		ft_putendl_fd.c		\
		ft_strchr.c			\
		ft_strlcpy.c		\
		ft_strnstr.c		\
		ft_tolower.c		\
		ft_bzero.c			\
		ft_isascii.c		\
		ft_memccpy.c		\
		ft_memmove.c		\
		ft_putnbr_fd.c		\
		ft_strdup.c			\
		ft_strlen.c			\
		ft_strrchr.c		\
		ft_toupper.c		\
		ft_calloc.c			\
		ft_isdigit.c		\
		ft_memchr.c			\
		ft_memset.c			\
		ft_putstr_fd.c		\
		ft_strjoin.c		\
		ft_strmapi.c		\
		ft_strtrim.c		\
		ft_isalnum.c		\
		ft_isprint.c		\
		ft_memcmp.c			\
		ft_putchar_fd.c		\
		ft_split.c			\
		ft_strlcat.c		\
		ft_strncmp.c		\
		ft_substr.c			\
		ft_get_nbchar.c		\
		ft_convert_basel.c	\
		ft_pow.c			\
		ft_atod_base.c		\
		ft_get_nbspace.c	\
		ft_get_nbprint.c	\
		ft_abs.c			\
		ft_getpos.c			\
		ft_atol_base.c		\
		ft_powl.c			\
		ft_ltoa_base.c		\
		ft_getposn.c		\
		ft_memseti.c		\
		ft_intlen.c			\
		ft_free_ret.c		\
		ft_rmchar.c			\
		ft_isonlychar.c		\
		ft_putstrret_fd.c	\
		ft_putstrreti_fd.c	\
		ft_strstrpart.c		\
		ft_is_in_a_row.c	\
		ft_swap.c			\
		ft_strcpy.c			\
		ft_isspace.c		\
		ft_appendstr.c		\
		ft_strjoin_free.c	\
		ft_realloc.c		\
		ft_ctos.c

SRCS_B	=	ft_lstnew_bonus.c	\
		ft_lstadd_front_bonus.c	\
		ft_lstsize_bonus.c	\
		ft_lstlast_bonus.c	\
		ft_lstadd_back_bonus.c	\
		ft_lstdelone_bonus.c	\
		ft_lstclear_bonus.c	\
		ft_lstiter_bonus.c	\
		ft_lstmap_bonus.c


OBJS	=	$(SRCS:.c=.o)

OBJS_B	=	$(SRCS_B:.c=.o)

HEAD	=	libft.h

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
