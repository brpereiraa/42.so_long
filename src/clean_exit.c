/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunolopes <brunolopes@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 10:06:19 by brunolopes        #+#    #+#             */
/*   Updated: 2023/12/05 19:22:04 by brunolopes       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void free_game(t_game **game)
{
	int	i;

	i = -1;
	if((*game)->map)
		free_map((*game)->map);
	if((*game)->sprites.collectible || (*game)->sprites.exit || (*game)->sprites.wall 
			|| (*game)->sprites.player1 || (*game)->sprites.grass)
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


