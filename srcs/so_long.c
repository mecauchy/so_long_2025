/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:10:43 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/02/18 13:02:05 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	destroy_prsentation(t_list *lst)
{
	if (lst->presentation_background)
		mlx_destroy_image(lst->mlx, lst->presentation_background);
	if (lst->start_button)
		mlx_destroy_image(lst->mlx, lst->start_button);
}

int	presentation_keypress(int key, t_list *lst)
{
	if (key == ENTER)
	{
		destroy_prsentation(lst);
		mlx_destroy_window(lst->mlx, lst->presentation_win);
		lst->window = mlx_new_window(lst->mlx, lst->longueur_map * 32,
				lst->largeur_map * 32, "so_long");
		assign_map(lst);
		find_position(lst);
		create_map(lst);
		mlx_hook(lst->window, KeyPress, KeyPressMask, key_press, lst);
		mlx_hook(lst->window, EXIT_CODE, 0, free_exit_game, lst);
		mlx_loop(lst->mlx);
	}
	return (0);
}

void	launch_presentation(t_list *lst)
{
	lst->presentation_win = mlx_new_window(lst->mlx, 800, 600, "GAME 01");
	mlx_put_image_to_window(lst->mlx, lst->presentation_win,
		lst->presentation_background, 0, 0);
	mlx_put_image_to_window(lst->mlx, lst->presentation_win,
		lst->start_button, 50, 50);
	mlx_put_image_to_window(lst->mlx, lst->presentation_win,
		lst->presentation_background, 100, 100);
	mlx_put_image_to_window(lst->mlx, lst->presentation_win,
		lst->start_button, 150, 150);
	mlx_put_image_to_window(lst->mlx, lst->presentation_win,
		lst->presentation_background, 200, 200);
	mlx_put_image_to_window(lst->mlx, lst->presentation_win,
		lst->start_button, 760, 0);
	mlx_put_image_to_window(lst->mlx, lst->presentation_win,
		lst->presentation_background, 710, 50);
	mlx_put_image_to_window(lst->mlx, lst->presentation_win,
		lst->start_button, 660, 100);
	mlx_put_image_to_window(lst->mlx, lst->presentation_win,
		lst->presentation_background, 610, 150);
	mlx_put_image_to_window(lst->mlx, lst->presentation_win,
		lst->start_button, 560, 200);
	mlx_string_put(lst->mlx, lst->presentation_win, 250, 300,
		0xFFFFFF, "---------- PRESS ENTER TO START THE GAME ----------");
	mlx_hook(lst->presentation_win, KeyPress, KeyPressMask,
		presentation_keypress, lst);
}

void	check_cmd_arguments(int ac, char **av)
{
	if (ac > 2)
		exit_error("Arguments : Too many arguments");
	if (ac < 2)
		exit_error("Arguments : Map file is missing");
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4))
		exit_error("Arguments : Map file is not a .ber file");
}

int	main(int ac, char **av)
{
	t_list	lst;

	check_cmd_arguments(ac, av);
	lst.path = av[1];
	lst.fd = open(lst.path, O_RDONLY);
	if (lst.fd < 0)
		exit_error("Error : Map file is missing");
	close(lst.fd);
	init_game(&lst);
	init_lst(&lst);
	parsing(&lst);
	lst.mlx = mlx_init();
	if (!lst.mlx)
	{
		free(lst.mlx);
		ft_error("Error : mlx_init() failed", &lst);
	}
	load_presentation_images(&lst);
	launch_presentation(&lst);
	mlx_loop(lst.mlx);
	free_all_game(&lst);
	close(lst.fd);
	return (0);
}
