/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpereir <brpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:34:47 by brpereir          #+#    #+#             */
/*   Updated: 2023/11/30 18:35:23 by brpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(void)
{
	exit(EXIT_SUCCESS);
}

int key_handler(int keycode, t_game **game)
{
	if(keycode == ESC)
		exit(EXIT_SUCCESS);
	(*game)->player.prev_x = (*game)->player.curr_x;
	(*game)->player.prev_y = (*game)->player.curr_y;
	if (keycode == W || keycode == UP)
		(*game)->player.curr_y--;
	if (keycode == S || keycode == DOWN)
		(*game)->player.curr_y++;
	if (keycode == D || keycode == RIGHT)
		(*game)->player.curr_x++;
	if (keycode == A || keycode == LEFT)
		(*game)->player.curr_x--;
	if ((*game)->map[(*game)->player.curr_y][(*game)->player.curr_x] == '1')
	{
		(*game)->player.curr_y = (*game)->player.prev_y;
		(*game)->player.curr_x = (*game)->player.prev_x;
		return (0);
	}
	(*game)->map[(*game)->player.prev_y][(*game)->player.prev_x] = '0';
	(*game)->map[(*game)->player.curr_y][(*game)->player.curr_x] = 'P';
	put_image(game);
	return (0);
}
