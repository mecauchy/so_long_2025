/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:42:50 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/02/18 12:07:22 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_all_game(t_list *lst)
{
	destroy_images(lst);
	if (lst->map)
		free_map(lst->map);
	mlx_destroy_window(lst->mlx, lst->window);
	mlx_destroy_display(lst->mlx);
	free(lst->mlx);
}

void	ft_error(char *message, t_list *lst)
{
	if (lst)
		free(lst);
	ft_printf(RED"\nError\n"GREY"%s\n"RESET, message);
	exit(EXIT_FAILURE);
}

void	ft_free_error(char *message, t_list *lst)
{
	free_map(lst->map);
	free_map(lst->map_copy);
	ft_printf(RED"\nError\n"GREY"%s\n"RESET, message);
	exit(EXIT_FAILURE);
}

void	exit_error(char *message)
{
	ft_printf(RED"\nError\n"GREY"%s\n"RESET, message);
	exit(EXIT_FAILURE);
}
