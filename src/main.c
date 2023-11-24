/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunolopes <brunolopes@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 10:06:19 by brunolopes        #+#    #+#             */
/*   Updated: 2023/11/21 16:36:24 by brunolopes       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;
// 	t_vars	vars;
// 	t_game	game;
// 	void	*image;
// 	int x = 0;
// 	int y = 0;

// 	img.width = 31;
// 	img.height = 35;
	
// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Save Juan!");
// 	img.img = mlx_xpm_file_to_image(vars.mlx, PLAYER_1, &img.width, &img.height);
// 	mlx_put_image_to_window(vars.mlx, vars.win, img.img, x * SIZE, y * SIZE);
// 	mlx_hook(vars.win, 17, 1L << 2, close_window, &vars);
// 	mlx_hook(vars.win, 2, 1L << 0, key_handler, &vars);
// 	mlx_loop(vars.mlx);
// }

static void game_hooks(t_game **game, t_vars **vars, t_data **data)
{
	// (*data)->img = mlx_xpm_file_to_image((*vars)->mlx, PLAYER_1, (*data)->width, (*data)->width);
	mlx_hook((*vars)->win, 17, 1L << 2, close_window, vars);
	mlx_hook((*vars)->win, 2, 1L << 0, key_handler, vars);
	mlx_loop((*vars)->mlx);
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
	t_vars *vars;
	t_data *data;
	int i = -1;

	vars = (t_vars *)malloc(sizeof(t_vars));
	data = (t_data *)malloc(sizeof(t_data));
	if(argc != 2)
		return (0);
	map_init(&game, argv);
	map_verifications(game);
	vars->mlx = mlx_init();
 	vars->win = mlx_new_window(vars->mlx, TILES_SIZE * game->rows, TILES_SIZE * game->columns, "so_long");
	open_image(&game, vars);
	game_hooks(&game, &vars, &data);
	print_map(game);
	return (0);
}
