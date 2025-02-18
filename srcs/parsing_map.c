/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:43:33 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/02/18 12:43:34 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_valide_map(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst->map)
		ft_free_error("Invalid map format", lst);
	while (lst->map[i])
	{
		if (!lst->map[i])
			ft_free_error("Invalid map format\n", lst);
		if (ft_strlen(lst->map[i]) != lst->longueur_map)
		{
			ft_free_error("Invalid map format\n", lst);
		}
		i++;
	}
	if (i != lst->largeur_map)
		ft_free_error("Invalid map.\nEmpty line in map\n", lst);
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
		ft_free_error("Invalid map.\nIt must be surrounded by a wall ", lst);
	while (k < lst->longueur_map && lst->map[lst->largeur_map - 1][k] == '1')
		k++;
	while (l < lst->largeur_map && lst->map[l][lst->longueur_map - 1] == '1')
		l++;
	if (k != lst->longueur_map || l != lst->largeur_map || k != i || l != j)
		ft_free_error("Invalid map.\nIt must be surrounded by a wall ", lst);
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
	flood_fill(map, x + 1, y, lst);
	flood_fill(map, x - 1, y, lst);
	flood_fill(map, x, y + 1, lst);
	flood_fill(map, x, y - 1, lst);
}

void	validate_path(t_list *lst)
{
	lst->map_info.nb_collectible_found = lst->map_info.nb_collectible;
	lst->map_info.nb_exit_found = 1;
	find_position(lst);
	flood_fill(lst->map_copy, lst->x, lst->y, lst);
	if (lst->map_info.nb_collectible_found != 0
		|| lst->map_info.nb_exit_found != 0)
	{
		ft_putendl_fd("Error : No valid path", 2);
		free_map(lst->map_copy);
		free_map(lst->map);
		exit(EXIT_FAILURE);
	}
	free_map(lst->map_copy);
}
