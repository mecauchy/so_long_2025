/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:48:45 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/02/17 17:25:55 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_valide_map(t_list *lst)
{
	int	i = 0;
	
	if (!lst->map)
		ft_free_error("Invalid map format", lst);
	while (lst->map[i])
	{
		printf("map[i] == %d, lst.largeur == %d\n", ft_strlen(lst->map[i]), lst->largeur_map);
		if (!lst->map[i])
			ft_free_error("ERR02\n", lst);
		if (ft_strlen(lst->map[i]) != lst->longueur_map)
		{
			ft_free_error("ERR03\n", lst);
		}
		i++;
	}
	if (i != lst->largeur_map)
		ft_free_error("Invalid map.\nEmpty line in map\n", lst);
}

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
	{
		close(file);
		ft_error("Memory allocation failed", lst);
	}
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
		{
			close(file);
			ft_error("Memory allocation failed", lst);
		}
	}
	lst->map = ft_split(lst->stock, '\n');
	lst->map_copy = ft_split(lst->stock, '\n');
	free(lst->stock);
	lst->stock = NULL;
	if (!lst->map || !lst->map_copy)
	{
		close(file);
		ft_error("Invalid map format", lst);
	}
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

void	check_corner(t_list *lst)
{
	int	i;
	int	j;
	int	k;
	int	l;
	
	i = 0;
	j = 0;
	k = 0;
	l = 0;
	while (i < lst->longueur_map && lst->map[0][i] == '1')
		i++;
	while (j < lst->largeur_map && lst->map[j][0] == '1')
		j++;
	if (i != lst->longueur_map || j != lst->largeur_map)
		ft_free_error("-01-Invalid corner in map.\nthe map must be surrounded by a wall ", lst);
	while (k < lst->longueur_map && lst->map[lst->largeur_map - 1][k] == '1')
		k++;
	while (l < lst->largeur_map && lst->map[l][lst->longueur_map - 1] == '1')
		l++;
	if (k != lst->longueur_map || l != lst->largeur_map || k != i || l != j)
		ft_free_error("Invalid corner in map.\nthe map must be surrounded by a wall ", lst);
	if (!check_size_line(lst))
		ft_free_error("Invalide size map", lst);
}

void	flood_fill(char **map, int x, int y, t_list *lst)
{
	if (map[y][x] == 'C')
	{
		lst->map_info.nb_collectible_found--;
		map[y][x] = '1';
	}
	else if (map[y][x] == 'E')
	{
		lst->map_info.nb_exit_found--;
		map[y][x] = '1';
		return ;
	}
	else if (map[y][x] == 'P' || map[y][x] == '0')
		map[y][x] = '1';
	else
		return ;
	// map[y][x] = 'X';
	flood_fill(map, x + 1, y, lst);
	flood_fill(map, x - 1, y, lst);
	flood_fill(map, x, y + 1, lst);
	flood_fill(map, x, y - 1, lst);
}

void		validate_path(t_list *lst)
{
	lst->map_info.nb_collectible_found = lst->map_info.nb_collectible;
	lst->map_info.nb_exit_found = 1;
	find_position(lst);
	flood_fill(lst->map_copy, lst->x, lst->y, lst);
	if (lst->map_info.nb_collectible_found != 0 || lst->map_info.nb_exit_found != 0)
	{
		ft_putendl_fd("Error : No valid path", 2);
		free_map(lst->map_copy);
		free_map(lst->map);
		exit(EXIT_FAILURE);
	}
	free_map(lst->map_copy);
}

void	fill_mapinfo(t_list *lst)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < lst->largeur_map)
	{
		x = 0;
		while (x < lst->longueur_map)
		{
			if (!strchr("01CEP", lst->map[y][x]))
				ft_free_error("Invalid Map.\nNot expected character in map", lst);
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
		ft_free_error("Invalid Map. There must be at least one collectible", lst);
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