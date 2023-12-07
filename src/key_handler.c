/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpereir <brpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:34:47 by brpereir          #+#    #+#             */
/*   Updated: 2023/12/07 17:18:03 by brpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(t_game **game)
{
	free_game(game, 3);
	exit (EXIT_SUCCESS);
}

static void	move_check(t_game **game)
{
	static int	flag;
	static int	i;

	if ((*game)->map[(*game)->player.curr_y][(*game)->player.curr_x] == 'C')
		(*game)->collectibles--;
	if ((*game)->map[(*game)->player.curr_y][(*game)->player.curr_x] == 'E' 
						&& !(*game)->collectibles)
	{
		ft_printf ("You won");
		free_game (game, 3);
	}
	if ((*game)->map[(*game)->player.curr_y][(*game)->player.curr_x] == 'E')
		flag = 1;
	if (flag == 2)
	{
		(*game)->map[(*game)->player.prev_y][(*game)->player.prev_x] = 'E';
		flag = 0;
	}
	else 
		(*game)->map[(*game)->player.prev_y][(*game)->player.prev_x] = '0';
	if (flag == 1)
		flag = 2;
	(*game)->map[(*game)->player.curr_y][(*game)->player.curr_x] = 'P';
	ft_printf ("%i\n", ++i);
}

int	key_handler(int keycode, t_game **game)
{
	if (keycode == ESC)
		free_game (game, 3);
	(*game)->player.prev_x = (*game)->player.curr_x;
	(*game)->player.prev_y = (*game)->player.curr_y;
	if (keycode == W || keycode == UP)
		(*game)->player.curr_y--;
	else if (keycode == S || keycode == DOWN)
		(*game)->player.curr_y++;
	else if (keycode == D || keycode == RIGHT)
		(*game)->player.curr_x++;
	else if (keycode == A || keycode == LEFT)
		(*game)->player.curr_x--;
	else 
		return (0);
	if ((*game)->map[(*game)->player.curr_y][(*game)->player.curr_x] == '1')
	{
		(*game)->player.curr_y = (*game)->player.prev_y;
		(*game)->player.curr_x = (*game)->player.prev_x;
		return (0);
	}
	move_check (game);
	put_image (game);
	return (0);
}
