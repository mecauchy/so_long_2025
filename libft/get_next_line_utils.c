/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:19:21 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/02/06 11:13:12 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_find_newline(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '\n')
			return (&s[i]);
		i++;
	}
	return (NULL);
}

// int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strdup(char *s1)
// {
// 	char	*ret;
// 	int		i;

// 	i = 0;
// 	if (!s1)
// 		return (NULL);
// 	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
// 	if (!ret)
// 	{
// 		return (NULL);
// 	}
// 	while (s1[i])
// 	{
// 		ret[i] = s1[i];
// 		i++;
// 	}
// 	ret[i] = '\0';
// 	return (ret);
// }

// char	*ft_strjoin(char *next_str, char *buff)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	if (!next_str)
// 	{
// 		next_str = (char *)malloc(sizeof(char) * 1);
// 		next_str[0] = '\0';
// 	}
// 	if (!buff || !next_str)
// 		return (NULL);
// 	str = malloc(sizeof(char) * ((ft_strlen(next_str) + ft_strlen(buff)) + 1));
// 	if (!str)
// 		return (NULL);
// 	i = -1;
// 	j = 0;
// 	if (next_str)
// 		while (next_str[++i])
// 			str[i] = next_str[i];
// 	while (buff[j])
// 		str[i++] = buff[j++];
// 	str[ft_strlen(next_str) + ft_strlen(buff)] = '\0';
// 	free(next_str);
// 	return (str);
// }
