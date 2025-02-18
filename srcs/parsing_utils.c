/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:43:42 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/02/18 13:06:27 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_only_sep(char *str)
{
	while (*str)
	{
		if (*str)
			return (0);
		str++;
	}
	return (1);
}

void	close_error(int file, char *message, t_list *lst)
{
	close(file);
	ft_error(message, lst);
}

void	stock_map(t_list *lst)
{
	char	*line;
	char	*tmp;
	int		file;

	file = open(lst->path, O_RDONLY);
	if (file < 0)
		exit_error("The map couldn't be opened");
	lst->stock = ft_strdup("");
	if (!lst->stock)
		close_error(file, "Memory allocation failed", lst);
	while (1)
	{
		line = get_next_line(file);
		if (!line)
			break ;
		tmp = lst->stock;
		lst->stock = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
		if (!lst->stock)
			close_error(file, "Memory allocation failed", lst);
	}
	lst->map = ft_split(lst->stock, '\n');
	lst->map_copy = ft_split(lst->stock, '\n');
	free(lst->stock);
	lst->stock = NULL;
	if (!lst->map || !lst->map_copy)
		close_error(file, "Invalid map format", lst);
	close(file);
}

int	check_size_line(t_list *lst)
{
	int	x;
	int	y;

	y = 0;
	while (lst->map[y])
	{
		x = 0;
		while (lst->map[y][x])
		{
			x++;
		}
		if (x != lst->longueur_map)
			return (0);
		y++;
	}
	return (1);
}

void	check_size(t_list *lst)
{
	if (lst->largeur_map < 3 || lst->longueur_map < 3)
		ft_free_error("Invalid size", lst);
}
