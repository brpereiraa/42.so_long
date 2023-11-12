/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpereir <brpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 10:06:19 by brunolopes        #+#    #+#             */
/*   Updated: 2023/11/12 19:12:22 by brpereir         ###   ########.fr       */
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

// 	int fd;
// 	game.rows = rows_size("./maps/map1.ber");
// 	printf("lines: %zu", game.rows);
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

static void map_init(t_game **game, char **argv)
{
	*game = (t_game *)malloc(sizeof(t_game));
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
	int i = -1;

	if(argc != 2)
		return (0);
	map_init(&game, argv);
	project_tester(&game);
	return (0);
}
