/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpereir <brpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 10:06:19 by brunolopes        #+#    #+#             */
/*   Updated: 2023/12/05 12:35:39 by brpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void free_game(t_game **game)
{
	int	i;

	i = -1;
	if((*game)->map)
	{
		while((*game)->map[++i]){
			free((*game)->map[i]);
		}
		free((*game)->map);
	}
	if((*game)->sprites.collectible)
	{
		mlx_destroy_image((*game)->mlx, (*game)->sprites.collectible);
		mlx_destroy_image((*game)->mlx, (*game)->sprites.exit);
		mlx_destroy_image((*game)->mlx, (*game)->sprites.wall);
		mlx_destroy_image((*game)->mlx, (*game)->sprites.player1);
		mlx_destroy_image((*game)->mlx, (*game)->sprites.grass);
	}
	if((*game)->win)
		mlx_destroy_window((*game)->mlx, (*game)->win);
	if((*game)->mlx)
		mlx_destroy_display((*game)->mlx);
	free((*game)->mlx);	
	free(*game);
	exit (1);
}
