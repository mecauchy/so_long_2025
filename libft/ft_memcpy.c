/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:16:20 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/02/06 11:04:57 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*v_dest;
	unsigned char	*v_src;
	int				i;

	if (!dest && !src)
		return (NULL);
	v_dest = (unsigned char *)dest;
	v_src = (unsigned char *)src;
	i = 0;
	while (n)
	{
		v_dest[i] = v_src[i];
		i++;
		n--;
	}
	return (dest);
}
