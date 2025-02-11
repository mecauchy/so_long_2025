# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/16 13:29:09 by mcauchy-          #+#    #+#              #
#    Updated: 2024/11/20 12:09:51 by mcauchy-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	=	ft_printf.c putnbrs.c search_other.c search.c srcs.c
			
OBJS	=	$(SRCS:.c=.o)

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	libftprintf.a

HEADER	=	ft_printf.h

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			ar rc $@ $^

%.o		:	%.c
			$(CC) $(CFLAGS) -o $@ -c $^

clean	:	
			/bin/rm -rf $(OBJS)

fclean	:	clean
			/bin/rm -rf $(NAME)

re		:	fclean all