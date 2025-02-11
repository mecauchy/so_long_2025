/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:48:45 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/02/11 20:39:30 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// void	check_valide_map(t_list *lst)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	while (lst->map[y])
// 	{
// 		x = 0;
// 		while (lst->map[y][x])
// 		{
// 			if (!strchr("01CEP", lst->map[y][x]))
// 				ft_error("Invalid Map. Not expected character in map", lst);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	check_file(t_list *lst)
// {
// 	int	file;

// 	file = open(lst->path, O_RDONLY);
// 	if (file < 0)
// 	{
// 		ft_putendl_fd("Error : can't open file", 2);
// 		exit(1);
// 	}
// 	if (ft_strcmp(ft_strrchr(lst->path, '.'), ".ber") != 0)
// 	{
// 		ft_putendl_fd("Error : invalid file", 2);
// 		exit(1);
// 	}
// }

void	stock_map(t_list *lst)
{
	char	*line;
	char	*tmp;
	int		file;
	
	file = open(lst->path, O_RDONLY);
	if (file < 0)
		ft_error("The map couldn't be opened", lst);
	line = get_next_line(file);
	if (!line)
		return ;
	lst->stock = ft_strdup("");
	if (!lst->stock)
		free(line);
	while (line)
	{
		tmp = lst->stock;
		lst->stock = ft_strjoin(lst->stock, line);
		free(tmp);
		free(line);
		line = get_next_line(file);
	}
	lst->map = ft_split(lst->stock, '\n');
	if (!lst->map)
	{
		ft_putendl_fd("Error : invalid map 01", 2);
		free(lst->stock);
		free(line);
		close(file);
		exit(1);
	}
	close(file);
	// free(line);
	free(lst->stock);
}

// void	stock_map(t_list *lst)
// {
// 	char	*line;
// 	char	*tmp;
// 	int		file;

// 	file = open(lst->path, O_RDONLY);
// 	if (file < 0)
// 		ft_error("The map couldn't be opened", lst);
// 	line = get_next_line(file);
// 	if (!line)
// 		return ;
// 	lst->stock = ft_strdup("");
// 	if (!lst->stock)
// 	{
// 		free(line);  // Correction 3: Libère line si ft_strdup échoue
// 		close(file);
// 		ft_error("Memory allocation failed", lst);
// 	}
// 	while (line)
// 	{
// 		tmp = lst->stock;
// 		lst->stock = ft_strjoin(tmp, line);
// 		free(tmp);
// 		free(line);
// 		if (!lst->stock)  // Correction 2: Gestion d'erreur ft_strjoin
// 		{
// 			close(file);
// 			ft_error("Memory allocation failed", lst);
// 		}
// 		line = get_next_line(file);
// 	}
// 	lst->map = ft_split(lst->stock, '\n');
// 	if (!lst->map)
// 	{
// 		ft_putendl_fd("Error : invalid map 01", 2);
// 		free(lst->stock);
// 		close(file);
// 		exit(1);
// 	}
// 	close(file);
// 	// free(lst->stock);  // Correction 1: Supprimé pour éviter le double free
// }

void	check_corner(t_list *lst)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < lst->longueur_map && lst->map[0][i] == '1')
		i++;
	while (j < lst->largeur_map && lst->map[j][0] == '1')
		j++;
	if (i != lst->longueur_map || j != lst->largeur_map)
	{
		ft_error("Invalid Map. invalid corner in map the map must be surrounded by a wall ", lst);
		exit(1);
	}
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
				ft_error("Invalid Map. Not expected character in map", lst);
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
	{
		ft_putendl_fd("Error : cannot open file", 2);
		exit(1);		
	}
	line = get_next_line(lst->fd);
	while (line != NULL)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			len--;
		if (count == 0)
			lst->longueur_map = len;
		else if (lst->longueur_map != len)
		{		
			ft_putendl_fd("Error : invalid map 02", 2);
			free(line);
			free(lst->stock);
			if (lst->map)
				free_map(lst->map);
			close(lst->fd);
			exit(1);
		}
		free(line);
		line = get_next_line(lst->fd);
		count++;
	}
	// free(line);
	lst->largeur_map = count;
	close(lst->fd);
	return (count);
}

void	check_parameters(t_list *lst)
{
	if (lst->map_info.nb_player != 1)
		ft_error("Invalid Map. There must be one player", lst);
	if (lst->map_info.nb_exit != 1)
		ft_error("Invalid Map. There must be one exit", lst);
	if (lst->map_info.nb_collectible == 0)
		ft_error("Invalid Map. There must be at least one collectible", lst);
}

// int	size_map(t_list *lst)
// {
// 	char	*line;
// 	int		count;
// 	int		len;
	
// 	count = 0;
// 	len = 0;
// 	lst->fd = open(lst->path, O_RDONLY);
// 	if (lst->fd < 0)
// 		return (0);
// 	line = get_next_line(lst->fd);
// 	if (!line)
// 		return (0);
// 	len = ft_strlen(line);
// 	if (len > 0 && line[len - 1] == '\n')
// 		lst->longueur_map = ft_strlen(line) - 1;
// 	else
// 		lst->longueur_map = ft_strlen(line);
// 	while (line)
// 	{
// 		count++;
// 		len = ft_strlen(line);
// 		if (len > 0 && line[len - 1] == '\n')
// 			len--;
// 		if (lst->longueur_map != len)
// 		{
// 			printf("count = %d\n", count);
// 			printf("line = %d\n", ft_strlen(line) - 1);			
// 			ft_putendl_fd("Error : invalid map 02", 2);
// 			exit(1);
// 		}
// 		printf("lst.longueur_map = %d\n", lst->longueur_map);
// 		printf("len = %d, tour = %d\n", len, count);
// 		free(line);
// 		line = get_next_line(lst->fd);
// 	}
// 	free(line);
// 	lst->largeur_map = count;
// 	close(lst->fd);
// 	printf("here");
// 	return (count);
// }

void	parsing(t_list *lst)
{
	// check_file(lst);
	size_map(lst);
	stock_map(lst);
	// check_valide_map(lst);
	check_corner(lst);
	fill_mapinfo(lst);
	check_parameters(lst);
	// gnl_cleanup();
}