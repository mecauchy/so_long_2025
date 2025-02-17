/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:52:47 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/02/17 17:27:42 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_list *lst)
{
	find_position(lst);
	if (lst->y > 0 && lst->map[lst->y - 1][lst->x] != '1')
	{
		if (lst->map[lst->y - 1][lst->x] == 'C')
		{
			lst->map[lst->y - 1][lst->x] = 'P';
			lst->map_info.nb_collectible--;
		}
		if (lst->map[lst->y - 1][lst->x] == 'E')
		{
			if (lst->map_info.nb_collectible == 0)
				exit_game(lst, 1);
		}
		if (lst->map[lst->y - 1][lst->x] == '0')
			lst->map[lst->y - 1][lst->x] = 'P';
		lst->map[lst->y][lst->x] = '0';
		lst->move++;
		update_window(lst);
	}
}

void	move_down(t_list *lst)
{
	find_position(lst);
	if (lst->y + 1 < lst->largeur_map && lst->map[lst->y + 1][lst->x] != '1')
	{
		if (lst->map[lst->y + 1][lst->x] == 'C')
		{
			lst->map[lst->y + 1][lst->x] = 'P';
			lst->map_info.nb_collectible--;
		}
		if (lst->map[lst->y + 1][lst->x] == 'E')
		{
			if (lst->map_info.nb_collectible == 0)
				exit_game(lst, 1);
		}
		if (lst->map[lst->y + 1][lst->x] == '0')
			lst->map[lst->y + 1][lst->x] = 'P';
		lst->map[lst->y][lst->x] = '0';
		lst->move++;
		update_window(lst);
	}
}

void	move_left(t_list *lst)
{
	find_position(lst);
	if (lst->x > 0 && lst->map[lst->y][lst->x - 1] != '1')
	{
		if (lst->map[lst->y][lst->x - 1] == 'C')
		{
			lst->map[lst->y][lst->x - 1] = 'P';
			lst->map_info.nb_collectible--;
		}
		if (lst->map[lst->y][lst->x - 1] == 'E')
		{
			if (lst->map_info.nb_collectible == 0)
				exit_game(lst, 1);
		}
		if (lst->map[lst->y][lst->x - 1] == '0')
			lst->map[lst->y][lst->x - 1] = 'P';
		lst->map[lst->y][lst->x] = '0';
		lst->move++;
		update_window(lst);
	}
}

void	move_right(t_list *lst)
{
	find_position(lst);
	if (lst->x + 1 < lst->longueur_map && lst->map[lst->y][lst->x + 1] != '1')
	{
		if (lst->map[lst->y][lst->x + 1] == 'C')
		{
			lst->map[lst->y][lst->x + 1] = 'P';
			lst->map_info.nb_collectible--;
		}
		if (lst->map[lst->y][lst->x + 1] == 'E')
		{
			if (lst->map_info.nb_collectible == 0)
			{
				exit_game(lst, 1);
			}
		}
		if (lst->map[lst->y][lst->x + 1] == '0')
			lst->map[lst->y][lst->x + 1] = 'P';
		lst->map[lst->y][lst->x] = '0';
		lst->move++;
		update_window(lst);
	}
}
