/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpereir <brpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 10:06:19 by brunolopes        #+#    #+#             */
/*   Updated: 2023/11/30 18:33:11 by brpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void game_hooks(t_game **game, t_data **data)
{
	mlx_hook((*game)->win, 17, 1L << 2, close_window, game);
	mlx_hook((*game)->win, 2, 1L << 0, key_handler, game);
	mlx_loop((*game)->mlx);
}

static void map_init(t_game **game, char **argv)
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

static void print_map(t_game *game)
{
	int	i;

	i = -1;
	while(game->map[++i])
		ft_printf("Line %i: %s\n", i, game->map[i]);
}

int main(int argc, char **argv)
{
	t_game *game;
	t_data *data;
	int i = -1;

	data = (t_data *)malloc(sizeof(t_data));
	if(argc != 2)
		return (0);
	map_init(&game, argv);
	map_verifications(game);
	game->mlx = mlx_init();
 	game->win = mlx_new_window(game->mlx, TILES_SIZE * game->columns, TILES_SIZE * game->rows, "so_long");
	open_image(&game);
	get_player(&game);
	game_hooks(&game, &data);
	print_map(game);
	return (0);
}
