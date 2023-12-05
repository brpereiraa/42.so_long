/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunolopes <brunolopes@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 10:06:19 by brunolopes        #+#    #+#             */
/*   Updated: 2023/12/05 20:48:36 by brunolopes       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void free_game(t_game **game, int flag)
{
	if (flag >= 1)
		free_map((*game)->map);
	if (flag == 2) 
		free_mlx(game);
	if (flag >= 3)
	{
		free_sprites(game);
		free_mlx(game);
	}
	free(*game);
	exit (1);
}

void free_mlx(t_game **game)
{
	mlx_destroy_window((*game)->mlx, (*game)->win);
	mlx_destroy_display((*game)->mlx);
	free((*game)->mlx);	
}

void free_sprites(t_game **game)
{
	mlx_destroy_image((*game)->mlx, (*game)->sprites.collectible);
	mlx_destroy_image((*game)->mlx, (*game)->sprites.exit);
	mlx_destroy_image((*game)->mlx, (*game)->sprites.wall);
	mlx_destroy_image((*game)->mlx, (*game)->sprites.player1);
	mlx_destroy_image((*game)->mlx, (*game)->sprites.grass);
}

void free_map(char	**map)
{
	int	i;
	
	i = -1;
    if(map != NULL)
    {
        while(map[++i])
            free(map[i]);
        free(map);
    }
}


