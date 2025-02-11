/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:55:13 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/02/06 10:54:14 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H	

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

// GET_LINE //

char	*get_next_line(int fd);
char	*read_to_next_str(char *next_str, int fd);
char	*ft_get_line(char *next_str);
char	*new_line(char *next_str);

// UTILS //

// int		ft_strlen(char *str);
char	*ft_find_newline(char *s);
// char	*ft_strjoin(char *next_str, char *buff);
// char	*ft_strdup(char *s1);

#endif