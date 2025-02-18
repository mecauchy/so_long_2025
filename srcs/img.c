/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:28:25 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/02/18 13:26:07 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_game(t_list *lst, int value)
{
	if (value)
		ft_printf(CYAN"you won the game after %d moves, congratulations!\n"
			RESET, lst->move);
	free_all_game(lst);
	exit(0);
}

int	free_exit_game(t_list *lst)
{
	ft_printf(CYAN"Sortie du jeu ...\n"RESET);
	free_all_game(lst);
	exit(EXIT_FAILURE);
	return (0);
}

void	check_size(t_list *lst)
{
	if (lst->largeur_map < 3 || lst->longueur_map < 3)
		ft_free_error("Invalid size", lst);
}

void	load_presentation_images(t_list *lst)
{
	int	img_larg;
	int	img_long;

	img_larg = 800;
	img_long = 600;
	lst->presentation_background = mlx_xpm_file_to_image(lst->mlx,
			"textures/presentation_background.xpm", &img_long, &img_larg);
	if (!lst->presentation_background)
	{
		ft_putendl_fd("Error : Failed to load presentation", 2);
		exit(1);
	}
	lst->start_button = mlx_xpm_file_to_image(lst->mlx,
			"textures/start_button.xpm", &img_long, &img_larg);
	if (!lst->start_button)
	{
		ft_putendl_fd("Error : Failed to load presentation", 2);
		exit(1);
	}
}

void	destroy_images(t_list *lst)
{
	if (lst->img_exit)
		mlx_destroy_image(lst->mlx, lst->img_exit);
	if (lst->img_floor)
		mlx_destroy_image(lst->mlx, lst->img_floor);
	if (lst->img_wall)
		mlx_destroy_image(lst->mlx, lst->img_wall);
	if (lst->img_coin)
		mlx_destroy_image(lst->mlx, lst->img_coin);
	if (lst->img_default)
		mlx_destroy_image(lst->mlx, lst->img_default);
	if (lst->player.player_up)
		mlx_destroy_image(lst->mlx, lst->player.player_up);
	if (lst->player.player_down)
		mlx_destroy_image(lst->mlx, lst->player.player_down);
	if (lst->player.player_left)
		mlx_destroy_image(lst->mlx, lst->player.player_left);
	if (lst->player.player_right)
		mlx_destroy_image(lst->mlx, lst->player.player_right);
	if (lst->img_perso && (lst->img_perso != lst->player.player_left
			&& lst->img_perso != lst->player.player_up && lst->img_perso
			!= lst->player.player_right && lst->img_perso
			!= lst->player.player_down))
		mlx_destroy_image(lst->mlx, lst->img_perso);
}
