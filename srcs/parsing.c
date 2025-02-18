/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:48:45 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/02/18 12:35:14 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_mapinfo(t_list *lst)
{
	int	x;
	int	y;

	y = 0;
	while (y < lst->largeur_map)
	{
		x = 0;
		while (x < lst->longueur_map)
		{
			if (!strchr("01CEP", lst->map[y][x]))
				ft_free_error("Not expected character in map", lst);
			else if (lst->map[y][x] == 'P')
			{
				lst->x = x;
				lst->y = y;
				lst->map_info.nb_player++;
			}
			else if (lst->map[y][x] == 'C')
				lst->map_info.nb_collectible++;
			else if (lst->map[y][x] == 'E')
				lst->map_info.nb_exit++;
			x++;
		}
		y++;
	}
}

int	size_map(t_list *lst)
{
	char	*line;
	int		count;
	int		len;

	count = 0;
	lst->fd = open(lst->path, O_RDONLY);
	if (lst->fd < 0)
		exit_error("Cannot open file");
	line = get_next_line(lst->fd);
	if (!line)
	{
		close(lst->fd);
		exit_error("Empty file");
	}
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len--;
	lst->longueur_map = len;
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(lst->fd);
	}
	lst->largeur_map = count;
	close(lst->fd);
	return (count);
}

void	check_parameters(t_list *lst)
{
	if (lst->map_info.nb_player != 1)
		ft_free_error("Invalid Map. There must be one player", lst);
	if (lst->map_info.nb_exit != 1)
		ft_free_error("Invalid Map. There must be one exit", lst);
	if (lst->map_info.nb_collectible == 0)
		ft_free_error("There must be at least one collectible", lst);
}

void	parsing(t_list *lst)
{
	size_map(lst);
	stock_map(lst);
	check_valide_map(lst);
	check_size(lst);
	check_corner(lst);
	fill_mapinfo(lst);
	check_parameters(lst);
	validate_path(lst);
}
