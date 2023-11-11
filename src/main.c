/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpereir <brpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 10:06:19 by brunolopes        #+#    #+#             */
/*   Updated: 2023/11/11 19:38:28 by brpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void rows_size(t_game **game)
{
	int		fd;

	(*game)->rows = 0;
	fd = open("./maps/map1.ber", O_RDONLY);
	while(get_next_line(fd))
		(*game)->rows++;
	close(fd);
}

// int verify_map(char *map)
// {
// 	size_t	size;
// 	int		fd;

// 	size = -1;
// 	fd = open(map, O_RDONLY);
// 	while(size == -1 || size == get_next_line(fd))
// 	{
		
// 	}
// }

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

static void print_map(t_game *game)
{
	int	i;

	i = -1;
	while(game->map[++i])
		ft_printf("Line %i: %s", i, game->map[i]);	
}


int main(void)
{
	t_game *game;
	int	fd;
	int i = -1;

	game = (t_game *)malloc(sizeof(t_game));
    if (game == NULL) 
        return (-1);
	game->columns = 0;
	fd = open("./maps/map2.ber", O_RDONLY);
	ft_check_cols(&game, fd);
	close(fd);
	fd = open("./maps/map2.ber", O_RDONLY);	
	read_map(fd, &game);
	print_map(game);

	return (0);
}
