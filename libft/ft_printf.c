/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:23:11 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/02/06 11:05:50 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_print_exec(va_list arg, char *format)
{
	if (*format == 's')
		return (ft_search_s(arg));
	else if (*format == 'c')
		return (ft_search_c(arg));
	else if (*format == 'p')
		return (ft_search_p(arg));
	else if (*format == 'd' || *format == 'i')
		return (ft_search_d_i(arg));
	else if (*format == 'x')
		return (ft_search_x(arg));
	else if (*format == 'X')
		return (ft_search_xx(arg));
	else if (*format == 'u')
		return (ft_search_u(arg));
	else if (*format == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list			arg;
	int				i;
	int				res;

	i = 0;
	res = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			res += ft_print_exec(arg, (char *)format + i + 1);
			i++;
		}
		else
			res += ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (res);
}
