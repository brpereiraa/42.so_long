/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpereir <brpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:34:47 by brpereir          #+#    #+#             */
/*   Updated: 2023/11/30 17:44:35 by brpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(void)
{
	exit(EXIT_SUCCESS);
}

static void update_map(t_game **game)
{
	
}

static void move_checker(t_game **game, char flag)
{
	(*game)->player.prev_x = (*game)->player.curr_x;
	(*game)->player.prev_y = (*game)->player.curr_y;
	if (flag == 'u')
	{
		if ((*game)->map[(*game)->player.curr_y - 1][(*game)->player.curr_x] == '1')
			return ;
		(*game)->player.curr_y--;
	}
	if (flag == 'd')
	{
		if ((*game)->map[(*game)->player.curr_y + 1][(*game)->player.curr_x] == '1')
			return ;
		(*game)->player.curr_y++;
	}
	if (flag == 'r')
	{
		if ((*game)->map[(*game)->player.curr_y][(*game)->player.curr_x + 1] != '1')
			return ;
		(*game)->player.curr_x++;
	}
	if (flag == 'l')
	{
		if ((*game)->map[(*game)->player.curr_y][(*game)->player.curr_x  - 1] == '1')
			return ;
		(*game)->player.curr_x--;
	}
	(*game)->map[(*game)->player.prev_y][(*game)->player.prev_x] = '0';
	(*game)->map[(*game)->player.curr_y][(*game)->player.curr_x] = 'P';
	put_image(game);
}

int key_handler(int keycode, t_game **game)
{
	if(keycode == ESC)
		exit(EXIT_SUCCESS);
	else if (keycode == W || keycode == UP)
		move_checker(game, 'u');
	else if (keycode == A || keycode == LEFT)
		move_checker(game, 'l');
	else if (keycode == S || keycode == DOWN)
		move_checker(game, 'd');
	else if (keycode == D || keycode == RIGHT)
		move_checker(game, 'r');
	return (0);
	
}
