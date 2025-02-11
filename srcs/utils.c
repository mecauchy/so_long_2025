/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:29:15 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/02/10 12:51:20 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	find_position(t_list *lst)
{
	int	pos_x;
	int	pos_y;

	pos_x = 0;
	pos_y = 0;
	if (!lst->map)
		exit(1);
	// while (pos_y < lst->largeur_map)
	while (lst->map[pos_y])
	{
		pos_x = 0;
		// while (pos_x < lst->longueur_map)
		while (lst->map[pos_y][pos_x])
		{
			if (lst->map[pos_y][pos_x] == 'P')
			{
				lst->y = pos_y;
				lst->x = pos_x;
				printf("pos_x == %d\n", pos_x);
				printf("pos_y == %d\n", pos_y);
				// return ;
			}
			pos_x++;
		}
		pos_y++;
	}
}

void	update_window(t_list *lst)
{
	mlx_clear_window(lst->mlx, lst->window);
	find_position(lst);
	create_map(lst);
}

// void	free_map(t_list *lst)
// {
// 	int	i;
// 	i = 0;
// 	while (lst->map[i])
// 	{
// 		free(lst->map[i]);
// 		i++;
// 	}
// 	free(lst->map);
// }

void	error_game(char *err)
{
	ft_putstr_fd(err, 2);
	exit(1);
}
