/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:56:12 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/02/13 12:35:04 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	stock_map(t_list *lst)
{
	char	*line;
	char	*tmp;
	int		file;
	int		count;
	int		fd;
	int		len;

	file = open(lst->path, O_RDONLY);
	if (file < 0)
		exit_error("The map couldn't be opened", lst);
	
	// Initialisation sécurisée du buffer
	lst->stock = ft_strdup("");
	if (!lst->stock)
	{
		close(file);
		ft_error("Memory allocation failed", lst);
	}

	// Lecture ligne par ligne
	while (1)
	{
		line = get_next_line(file);
		if (!line)
			break ;
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			len--;
		if (count == 0)
			lst->longueur_map = len;
		else if (lst->longueur_map != len)
		{
			close(fd);
			free(line);
			// gnl_cleanup();
			ft_error("Invalid map 02", lst);
		}
		// Jointure sécurisée avec gestion d'erreur
		tmp = lst->stock;
		lst->stock = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
		count++;
		if (!lst->stock)
		{
			close(file);
			ft_error("Memory allocation failed", lst);
		}
	}
	lst->largeur_map = count;
	// Conversion finale en map 2D
	lst->map = ft_split(lst->stock, '\n');
	free(lst->stock); // Libération IMMÉDIATE après split
	lst->stock = NULL;
	
	if (!lst->map)
	{
		close(file);
		gnl_cleanup(); // Nettoyage du buffer GNL
		ft_error("Invalid map format", lst);
	}
	close(file);
	gnl_cleanup(); // Nettoyage final du buffer GNL
}
