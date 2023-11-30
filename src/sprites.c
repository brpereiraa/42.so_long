/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpereir <brpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:31:22 by brunolopes        #+#    #+#             */
/*   Updated: 2023/11/24 12:24:29 by brpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	put_image(t_game **game, t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while(i < (*game)->columns)
	{
		j = 0;
		while(j < (*game)->rows)
		{
			if ((*game)->map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, (*game)->sprites.wall, j * TILES_SIZE, i * TILES_SIZE);
			if ((*game)->map[i][j] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, (*game)->sprites.grass, j * TILES_SIZE, i * TILES_SIZE);
			if ((*game)->map[i][j] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, (*game)->sprites.exit, j * TILES_SIZE, i * TILES_SIZE);
			if ((*game)->map[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, (*game)->sprites.collectible, j * TILES_SIZE, i * TILES_SIZE);
			if ((*game)->map[i][j] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, (*game)->sprites.player1, j * TILES_SIZE, i * TILES_SIZE);
			j++;
		}
		i++;
	}
}

void	open_image(t_game **game, t_vars *vars)
{
	int	img_size;

	img_size = 50;
	(*game)->sprites.player1 =  mlx_xpm_file_to_image(vars->mlx, PLAYER_1, &img_size, &img_size);
	(*game)->sprites.wall =  mlx_xpm_file_to_image(vars->mlx, WALL_TILE, &img_size, &img_size);
	(*game)->sprites.grass =  mlx_xpm_file_to_image(vars->mlx, FLOOR_TILE, &img_size, &img_size);
	(*game)->sprites.collectible =  mlx_xpm_file_to_image(vars->mlx, COLLECTIBLE_TILE, &img_size, &img_size);
	(*game)->sprites.exit =  mlx_xpm_file_to_image(vars->mlx, EXIT_TILE, &img_size, &img_size);
	put_image(game, vars);
}
