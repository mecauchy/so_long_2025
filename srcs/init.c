/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:34:22 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/02/18 13:34:46 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_lst(t_list *lst)
{
	lst->img_longueur = 32;
	lst->img_largeur = 32;
	lst->longueur_map = 0;
	lst->largeur_map = 0;
	lst->keycode = 0;
	lst->move = 0;
	lst->x = 0;
	lst->y = 0;
	lst->map_info.nb_coin = 0;
	lst->map_info.nb_exit = 0;
	lst->map_info.nb_player = 0;
	lst->map_info.nb_collectible = 0;
	lst->map_info.nb_collectible_found = 0;
	lst->map_info.nb_exit_found = 0;
}

void	init_game(t_list *lst)
{
	ft_bzero(lst, sizeof(lst));
	lst->window = NULL;
	lst->map = NULL;
	lst->img_wall = NULL;
	lst->img_exit = NULL;
	lst->img_coin = NULL;
	lst->img_perso = NULL;
	lst->img_default = NULL;
	lst->img_floor = NULL;
	lst->player.player_up = NULL;
	lst->player.player_down = NULL;
	lst->player.player_left = NULL;
	lst->player.player_right = NULL;
}
