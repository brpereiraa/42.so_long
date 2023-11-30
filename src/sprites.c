/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpereir <brpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:31:22 by brunolopes        #+#    #+#             */
/*   Updated: 2023/11/30 17:10:03 by brpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void	put_image(t_game **game)
{
	int	i;
	int	j;

	i = 0;
	while(i < (*game)->rows)
	{
		j = 0;
		while(j < (*game)->columns)
		{
			if ((*game)->map[i][j] == '1')
				mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->sprites.wall, j * TILES_SIZE, i * TILES_SIZE);
			if ((*game)->map[i][j] == '0')
				mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->sprites.grass, j * TILES_SIZE, i * TILES_SIZE);
			if ((*game)->map[i][j] == 'E')
				mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->sprites.exit, j * TILES_SIZE, i * TILES_SIZE);
			if ((*game)->map[i][j] == 'C')
				mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->sprites.collectible, j * TILES_SIZE, i * TILES_SIZE);
			if ((*game)->map[i][j] == 'P')
				mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->sprites.player1, j * TILES_SIZE, i * TILES_SIZE);
			j++;
		}
		i++;
	}
}

void	open_image(t_game **game)
{
	int	img_size;

	img_size = 50;
	(*game)->sprites.player1 =  mlx_xpm_file_to_image((*game)->mlx, PLAYER_1, &img_size, &img_size);
	(*game)->sprites.wall =  mlx_xpm_file_to_image((*game)->mlx, WALL_TILE, &img_size, &img_size);
	(*game)->sprites.grass =  mlx_xpm_file_to_image((*game)->mlx, FLOOR_TILE, &img_size, &img_size);
	(*game)->sprites.collectible =  mlx_xpm_file_to_image((*game)->mlx, COLLECTIBLE_TILE, &img_size, &img_size);
	(*game)->sprites.exit =  mlx_xpm_file_to_image((*game)->mlx, EXIT_TILE, &img_size, &img_size);
	put_image(game);
}

void get_player(t_game **game)
{
	int	i;
	int	j;

	i = 0;
	while(i < (*game)->rows)
	{
		j = -1;
		while(++j < (*game)->columns)
			if ((*game)->map[i][j] == 'P')
			{
				(*game)->player.curr_x = j;
				(*game)->player.curr_y = i;
				(*game)->player.prev_x = j;
				(*game)->player.prev_y = i;
			}
		i++;
	}
}
