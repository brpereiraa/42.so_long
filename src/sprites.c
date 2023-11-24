/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunolopes <brunolopes@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:31:22 by brunolopes        #+#    #+#             */
/*   Updated: 2023/11/21 16:28:20 by brunolopes       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	open_image(t_game **game, t_vars *vars)
{
	int	img_size;

	img_size = 64;
	(*game)->sprites.player1 =  mlx_xpm_file_to_image(vars->mlx, PLAYER_1, &img_size, &img_size);
	mlx_put_image_to_window(vars->mlx, vars->win, (*game)->sprites.player1, 0, 0);
}