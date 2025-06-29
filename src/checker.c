/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpereir <brpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:14:10 by brpereir          #+#    #+#             */
/*   Updated: 2023/12/11 19:37:53 by brpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	shape_check(t_game *game)
{
	size_t	size;
	int		i;

	i = -1;
	size = 1;
	while (game->map[++i])
	{
		if (ft_strlen(game->map[i]) != size && size != 1)
		{
			ft_printf("Error:\nMap is not a rectangle\n");
			return (1);
		}
		size = ft_strlen(game->map[i]);
	}
	return (0);
}

static int	wall_check(t_game *game)
{
	size_t	i;
	size_t	j;

	j = -1;
	i = game->columns - 1;
	while (++j < game->rows)
		if (game->map[j][0] != '1' || game->map[j][i] != '1')
			return (1);
	j = -1;
	i = game->rows - 1;
	while (++j < game->columns)
		if (game->map[0][j] != '1' || game->map[i][j] != '1')
			return (1);
	return (0);
}

static int	point_checker(t_game **game)
{
	size_t	i;
	size_t	j;

	i = -1;
	while ((*game)->map[++i])
	{
		j = -1;
		while ((*game)->map[i][++j])
		{
			if ((*game)->map[i][j] == 'C')
				(*game)->collectibles++;
			else if ((*game)->map[i][j] == 'E')
				(*game)->exit++;
			else if ((*game)->map[i][j] == 'P')
				(*game)->start++;
			else if ((*game)->map[i][j] != '0' && (*game)->map[i][j] != '1')
				return (1);
		}
	}
	if ((*game)->collectibles == 0 || (*game)->exit != 1 
		|| (*game)->start++ != 1)
		return (1);
	return (0);
}

static int	flood_fill(int total_coins, int x, int y, char **map)
{
	static int	collectibles;
	static int	exit;

	if (map[y][x] == '1')
		return (0);
	if (map[y][x] == 'C')
		collectibles++;
	if (map[y][x] == 'E')
		exit++;
	map[y][x] = '1';
	flood_fill(total_coins, x - 1, y, map);
	flood_fill(total_coins, x + 1, y, map);
	flood_fill(total_coins, x, y - 1, map);
	flood_fill(total_coins, x, y + 1, map);
	if (collectibles == total_coins && exit == 1)
		return (1);
	return (0);
}

void	map_verifications(t_game *game)
{
	char	**map_test;

	if (shape_check(game))
		free_game(&game, 1);
	if (point_checker(&game))
	{
		ft_printf("Error:\nWrong number of points or incorrect characters\n");
		free_game(&game, 1);
	}
	if (wall_check(game))
	{
		ft_printf("Map not surrounded by walls\n");
		free_game(&game, 1);
	}
	get_player(&game);
	map_test = dup_map(game);
	if (!flood_fill(game->collectibles, game->player.curr_x, 
			game->player.curr_y, map_test))
	{
		ft_printf("No possible exit\n");
		free_map(map_test);
		free_game(&game, 1);
	}
	free_map(map_test);
}
