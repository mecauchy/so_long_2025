/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:28:25 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/02/11 17:27:25 by mecauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_presentation_images(t_list *lst)
{
	int	img_larg;
	int	img_long;

	img_larg = 800;
	img_long = 600;
	lst->presentation_background = mlx_xpm_file_to_image(lst->mlx, "textures/presentation_background.xpm", &img_long, &img_larg);
	if (!lst->presentation_background)
	{
		ft_putendl_fd("Error : Failed to load presentation", 2);
		exit(1);
	}
	lst->start_button = mlx_xpm_file_to_image(lst->mlx, "textures/start_button.xpm", &img_long, &img_larg);
	if (!lst->start_button)
	{
		ft_putendl_fd("Error : Failed to load presentation", 2);
		exit(1);
	}
	// lst->start_button = mlx_xpm_file_to_image(lst->mlx, "textures/start_button.xpm", &img_long, &img_larg);
	// if (lst->start_button)
	// {
	// 	ft_putendl_fd("Error : Failed to load Start Button", 2);
	// 	exit (1);
	// }
}
