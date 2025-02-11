/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbrs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:07:29 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/02/06 11:05:39 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putnbr_u(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_putnbr_u(n / 10);
		count += ft_putnbr_u(n % 10);
	}
	if (n < 10)
	{
		count += ft_putchar(n + '0');
	}
	return (count);
}

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (nb < 0)
	{
		nb = -nb;
		count = ft_putchar('-');
	}
	if (nb >= 10)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	else
		count += ft_putchar(nb + '0');
	return (count);
}

int	ft_putnbr_hex_x(unsigned int nb)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		count += ft_putnbr_hex_x(nb / 16);
		count += ft_putnbr_hex_x(nb % 16);
	}
	else
		count += ft_putchar(base[nb % 16]);
	return (count);
}

int	ft_putnbr_hex_xx(unsigned int nb)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		count += ft_putnbr_hex_xx(nb / 16);
		count += ft_putnbr_hex_xx(nb % 16);
	}
	else
		count += ft_putchar(base[nb % 16]);
	return (count);
}

int	ft_putnbr_hex_p(unsigned long p)
{
	int				count;
	char			*base;

	count = 0;
	base = "0123456789abcdef";
	if (p >= 16)
	{
		count += ft_putnbr_hex_p(p / 16);
		count += ft_putnbr_hex_p(p % 16);
	}
	else
		count += ft_putchar(base[p % 16]);
	return (count);
}
