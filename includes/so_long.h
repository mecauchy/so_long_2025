/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:39:17 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/02/17 13:52:04 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

#define SO_LONG_H

# define UP			65362
# define DOWN		65364
# define LEFT		65361
# define RIGHT		65363

# define W			119
# define A			97
# define S			115
# define D			100

# define ESC		65307
# define SPACE		32
# define ENTER		65293

# define CYAN		"\033[1;96m"
# define RESET		"\033[0m"
# define RED		"\033[1;31m"
# define GREY 		"\033[0;90m"

# define EXIT_CODE	17

# include "../minilibx-linux/mlx.h"
# include "./libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>

typedef	struct s_img
{
	void	*player_up;
	void	*player_down;
	void	*player_left;
	void	*player_right;
}				t_img;

typedef	struct s_map
{
	unsigned int	nb_coin;
	unsigned int	nb_exit;	
	unsigned int	nb_player;
	unsigned int	nb_collectible;
}				t_map;

typedef	struct s_list
{
	void	*img;
	void	*mlx;
	char	**map;
	char	**map_copy;
	void	*window;
	void	*presentation_win;
	void	*img_wall;
	void	*img_exit;
	void	*img_coin;
	void	*img_perso;
	void	*img_floor;
	void	*img_default;
	void	*presentation_background;
	void	*start_button;
	void	*presentation_window;
	char	*path;
	int		img_longueur;
	int		img_largeur;
	int		longueur_map;
	int		largeur_map;
	int		keycode;
	int		move;
	int		fd;
	int		file;
	char	*stock;
	int		x;
	int		y;
	t_map	map_info;
	t_img	player;
}				t_list;

void			update_window(t_list *lst);
void			parsing(t_list *lst);
int				size_map(t_list *lst);
void			fill_mapinfo(t_list *lst);
void			check_corner(t_list *lst);
void			stock_map(t_list *lst);
// void			check_file(t_list *lst);
// void			check_valide_map(t_list *lst);
void			move_right(t_list *lst);
void			move_left(t_list *lst);
void			move_down(t_list *lst);
void			move_up(t_list *lst);
void			init_game(t_list *lst);
void			exit_game(t_list *lst, int value);
int				key_press(int key, t_list *lst);
int				create_map(t_list *lst);
void			find_position(t_list *lst);
void			assign_map(t_list *lst);
char			*player_move(t_list *lst);
int				free_exit_game(t_list *lst);
void			set_player_position(t_list *lst, int key);
void			launch_presentation(t_list *lst);
int				presentation_keypress(int key, t_list *lst);
void			load_presentation_images(t_list *lst);

void			ft_error(char *message, t_list *lst);
void			ft_free_error(char *message, t_list *lst);
void			destroy_images(t_list *lst);
void			free_all_game(t_list *lst);
void			free_map(char **map);
void			check_parameters(t_list *lst);
void			check_cmd_arguments(int ac, char **av);
void			gnl_cleanup(void);
int				check_size_line(t_list *lst);
void			check_valide_map(t_list *lst);
void			check_size(t_list *lst);
void			exit_error(char *message);

void			validate_path(t_list *lst);
void			flood_fill(char **map, int x, int y);

#endif