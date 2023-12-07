/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpereir <brpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 10:06:19 by brunolopes        #+#    #+#             */
/*   Updated: 2023/12/07 10:32:51 by brpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	game_hooks(t_game **game)
{
	mlx_hook ((*game)->win, 17, 1L << 2, close_window, game);
	mlx_hook ((*game)->win, 2, 1L << 0, key_handler, game);
	mlx_loop ((*game)->mlx);
}

static void	map_init(t_game **game, char **argv)
{
	*game = (t_game *)malloc(sizeof(t_game));
	(*game)->exit = 0;
	(*game)->start = 0;
	(*game)->collectibles = 0;
	if (game == NULL) 
		return ;
	cols_size(game, argv[1]);
	rows_size(game, argv[1]);
	read_map(game, argv[1]);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (0);
	map_init(&game, argv);
	map_verifications(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		free_game(&game, 2);
	game->win = mlx_new_window(game->mlx, TILES_SIZE * game->columns, 
			TILES_SIZE * game->rows, "so_long");
	if (!game->win)
		free_game(&game, 2);
	open_image(&game);
	get_player(&game);
	game_hooks(&game);
	return (0);
}
