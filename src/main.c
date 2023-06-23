/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunolopes <brunolopes@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 10:06:19 by brunolopes        #+#    #+#             */
/*   Updated: 2023/06/23 11:32:54 by brunolopes       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

inline int	close_window(void)
{
	exit(EXIT_SUCCESS);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Save Juan!");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 6, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 7, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 8, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 9, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 10, 0x00FF0000);
	my_mlx_pixel_put(&img, 6, 5, 0x00FF0000);
	my_mlx_pixel_put(&img, 6, 6, 0x00FF0000);
	my_mlx_pixel_put(&img, 6, 7, 0x00FF0000);
	my_mlx_pixel_put(&img, 6, 8, 0x00FF0000);
	my_mlx_pixel_put(&img, 6, 9, 0x00FF0000);
	my_mlx_pixel_put(&img, 6, 10, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 17, 1L << 2, close_window, &vars);
	mlx_loop(vars.mlx);
}