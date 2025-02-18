/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:44:28 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/02/18 12:44:31 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*player_move(t_list *lst)
{
	if (lst->keycode == UP || lst->keycode == W)
		return ("textures/player_up.xpm");
	if (lst->keycode == DOWN || lst->keycode == S)
		return ("textures/player_down.xpm");
	if (lst->keycode == LEFT || lst->keycode == A)
		return ("textures/player_left.xpm");
	if (lst->keycode == RIGHT || lst->keycode == D)
		return ("textures/player_right.xpm");
	return (NULL);
}

void	set_player_position(t_list *lst, int key)
{
	static int	index = 0;

	if (index == 0)
	{
		mlx_destroy_image(lst->mlx, lst->img_perso);
		index++;
	}
	if (key == UP || key == W)
		lst->img_perso = lst->player.player_up;
	if (key == DOWN || key == S)
		lst->img_perso = lst->player.player_down;
	if (key == LEFT || key == A)
		lst->img_perso = lst->player.player_left;
	if (key == RIGHT || key == D)
		lst->img_perso = lst->player.player_right;
}

int	key_press(int key, t_list *lst)
{
	if (key == ESC)
		free_exit_game(lst);
	set_player_position(lst, key);
	if (key == UP || key == W)
		move_up(lst);
	if (key == DOWN || key == S)
		move_down(lst);
	if (key == LEFT || key == A)
		move_left(lst);
	if (key == RIGHT || key == D)
		move_right(lst);
	return (0);
}
