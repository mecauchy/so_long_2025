# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 17:24:44 by mcauchy-          #+#    #+#              #
#    Updated: 2025/02/10 11:51:39 by mcauchy-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			ft_atoi.c ft_strlen.c ft_strjoin.c ft_putstr_fd.c ft_putnbr_fd.c \
			ft_memcpy.c ft_putchar_fd.c ft_memcmp.c ft_putendl_fd.c \
			ft_strncmp.c ft_memmove.c ft_memchr.c ft_strchr.c ft_memset.c \
			ft_bzero.c ft_strrchr.c ft_calloc.c ft_substr.c ft_toupper.c \
			ft_tolower.c  ft_strdup.c ft_strnstr.c ft_strtrim.c\
			ft_striteri.c ft_split.c ft_itoa.c ft_strcmp.c \
			ft_strmapi.c  ft_strlcpy.c ft_strlcat.c \
			ft_printf.c putnbrs.c search_other.c search.c srcs.c \
			get_next_line.c get_next_line_utils.c \


HEADER	=	libft.h

OBJS	=	$(SRCS:.c=.o)

NAME	=	libft.a

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			ar rc  $@ $^
			ranlib $@

%.o		:	%.c $(HEADER)
			$(CC) $(CFLAGS) -o $@ -c $<

clean	:
			/bin/rm -rf $(OBJS)

fclean	:	clean
			/bin/rm -rf $(NAME)

re		:	fclean all
