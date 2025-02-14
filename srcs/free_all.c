/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:42:50 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/02/14 12:05:39 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while(map[i])
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
	if (lst->img_perso && (lst->img_perso != lst->player.player_left && lst->img_perso != lst->player.player_up && lst->img_perso != lst->player.player_right && lst->img_perso != lst->player.player_down))
		mlx_destroy_image(lst->mlx, lst->img_perso);
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
	ft_printf(RED"\nError\n"GREY"%s\n"RESET, message);
	exit(EXIT_FAILURE);
}
void	exit_error(char *message)
{
	ft_printf(RED"\nError\n"GREY"%s\n"RESET, message);
	exit(EXIT_FAILURE);
}