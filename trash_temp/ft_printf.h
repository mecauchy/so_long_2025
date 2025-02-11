/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:27:30 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/02/06 10:46:21 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"


int	ft_printf(const char *format, ...);
int	ft_print_exec(va_list arg, char *format);

int	ft_search_s(va_list arg);
int	ft_search_c(va_list arg);
int	ft_search_p(va_list arg);
int	ft_search_d_i(va_list arg);
int	ft_search_u(va_list arg);
int	ft_search_x(va_list arg);
int	ft_search_xx(va_list arg);

int	ft_putnbr_u(unsigned int n);

int	ft_putnbr_hex_x(unsigned int nb);
int	ft_putnbr_hex_xx(unsigned int nb);
int	ft_putnbr_hex_p(unsigned long p);

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int n);

#endif