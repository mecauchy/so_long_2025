/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:10:43 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/02/13 16:33:42 by mcauchy-         ###   ########.fr       */
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

void	assign_map(t_list *lst)
{
	lst->img_wall = mlx_xpm_file_to_image(lst->mlx, "textures/wall.xpm", &lst->img_longueur, &lst->img_largeur);
	lst->img_coin = mlx_xpm_file_to_image(lst->mlx, "textures/collectible.xpm", &lst->img_longueur, &lst->img_largeur);
	lst->img_exit = mlx_xpm_file_to_image(lst->mlx, "textures/exit.xpm", &lst->img_longueur, &lst->img_largeur);
	lst->img_floor = mlx_xpm_file_to_image(lst->mlx, "textures/floor.xpm", &lst->img_longueur, &lst->img_largeur);
	lst->img_perso = mlx_xpm_file_to_image(lst->mlx, "textures/player.xpm", &lst->img_longueur, &lst->img_largeur);
	lst->img_default = mlx_xpm_file_to_image(lst->mlx, "textures/default.xpm", &lst->img_longueur, &lst->img_largeur);
	if (!lst->img_wall || !lst->img_coin || !lst->img_exit || !lst->img_floor || !lst->img_perso || !lst->img_default)
	{
		if (lst->map)
			free_map(lst->map);
		mlx_destroy_window(lst->mlx, lst->window);
		mlx_destroy_display(lst->mlx);
		free(lst->mlx);
		exit(EXIT_FAILURE);
	}
	lst->player.player_up = mlx_xpm_file_to_image(lst->mlx, "textures/player_up.xpm", &lst->img_longueur, &lst->img_largeur);
	lst->player.player_down = mlx_xpm_file_to_image(lst->mlx, "textures/player_down.xpm", &lst->img_longueur, &lst->img_largeur);
	lst->player.player_left = mlx_xpm_file_to_image(lst->mlx, "textures/player_left.xpm", &lst->img_longueur, &lst->img_largeur);
	lst->player.player_right = mlx_xpm_file_to_image(lst->mlx, "textures/player_right.xpm", &lst->img_longueur, &lst->img_largeur);
	if (!lst->player.player_up || !lst->player.player_down || !lst->player.player_left || !lst->player.player_right)
		ft_error("Missing player", lst);
		// free_all_game(lst);
}

int	create_map(t_list *lst)
{
	int	x;
	int	y;
	char	*step;
	char	*tmp;

	x = 0;
	y = 0;
	if (!lst->map)
		exit(1);
	while (y < lst->largeur_map)
	{
		x = 0;
		while (x < lst->longueur_map)
		{
			if (lst->map[y][x] == '1')
			{
				if (lst->img_wall == NULL)
					free_all_game(lst);	
				mlx_put_image_to_window(lst->mlx, lst->window, lst->img_wall, x * 32, y * 32);
			}
			if (lst->map[y][x] == '0')
				mlx_put_image_to_window(lst->mlx, lst->window, lst->img_floor, x * 32, y * 32);
			if (lst->map[y][x] == 'C')
				mlx_put_image_to_window(lst->mlx, lst->window, lst->img_coin, x * 32, y * 32);
			if (lst->map[y][x] == 'E')
				mlx_put_image_to_window(lst->mlx, lst->window, lst->img_exit, x * 32, y * 32);
			if (y == lst->y && x == lst->x)
				mlx_put_image_to_window(lst->mlx, lst->window, lst->img_default, x * 32, y * 32);
			x++;
		}
		y++;
	}
	tmp = ft_itoa(lst->move);
	step = ft_strjoin("steps : ", tmp);
	free(tmp);
	mlx_string_put(lst->mlx, lst->window, 10, 10, 0xFFFFFF, "Press ESC to quit");
	mlx_string_put(lst->mlx, lst->window, 10, 30, 0xFF0099, step);
	free(step);
	return (1);
}

// int	key_press(t_list *lst)
// {
// 	if (lst->keycode == ESC)
// 		exit(1);
// 	if (lst->keycode == UP || lst->keycode == W)
// 		move_up(lst);
// 	if (lst->keycode == DOWN || lst->keycode == S)
// 		move_down(lst);
// 	if (lst->keycode == LEFT || lst->keycode == A)
// 		move_left(lst);
// 	if (lst->keycode == RIGHT || lst->keycode == D)
// 		move_right(lst);
// 	return (0);
// }

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
	set_player_position(lst, key);
	if (key == ESC)
		free_exit_game(lst);
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

void	exit_game(t_list *lst, int value)
{
	if (value)
		ft_printf(CYAN"you won the game after %d moves, congratulations!\n"RESET, lst->move);
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
	lst->player.player_up = NULL;
	lst->player.player_down = NULL;
	lst->player.player_left = NULL;
	lst->player.player_right = NULL;
}

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
		lst->window = mlx_new_window(lst->mlx, lst->longueur_map * 32, lst->largeur_map * 32, "so_long");
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
	lst->presentation_win = mlx_new_window(lst->mlx, 800, 600, "-----GAME 01-----");
	mlx_put_image_to_window(lst->mlx, lst->presentation_win, lst->presentation_background, 0, 0);
	mlx_put_image_to_window(lst->mlx, lst->presentation_win, lst->start_button, 50, 50);
	mlx_put_image_to_window(lst->mlx, lst->presentation_win, lst->presentation_background, 100, 100);	
	mlx_put_image_to_window(lst->mlx, lst->presentation_win, lst->start_button, 150, 150);
	mlx_put_image_to_window(lst->mlx, lst->presentation_win, lst->presentation_background, 200, 200);	
	mlx_put_image_to_window(lst->mlx, lst->presentation_win, lst->start_button, 760, 0);
	mlx_put_image_to_window(lst->mlx, lst->presentation_win, lst->presentation_background, 710, 50);	
	mlx_put_image_to_window(lst->mlx, lst->presentation_win, lst->start_button, 660, 100);
	mlx_put_image_to_window(lst->mlx, lst->presentation_win, lst->presentation_background, 610, 150);	
	mlx_put_image_to_window(lst->mlx, lst->presentation_win, lst->start_button, 560, 200);
	mlx_string_put(lst->mlx, lst->presentation_win, 250, 300, 0xFFFFFF, "---------- PRESS ENTER TO START THE GAME ----------");
	mlx_hook(lst->presentation_win, KeyPress, KeyPressMask, presentation_keypress, lst);
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
