/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpereir <brpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:34:47 by brpereir          #+#    #+#             */
/*   Updated: 2023/11/30 11:04:07 by brpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(void)
{
	exit(EXIT_SUCCESS);
}

int key_handler(t_game **game, int keycode)
{
	if(keycode == ESC)
		exit(EXIT_SUCCESS);
	else if (keycode == W || keycode == UP)
	{
		(*game)->player.curr_y++;
		printf("UP\n");
	}
	else if (keycode == A || keycode == LEFT)
	{
		(*game)->player.curr_x--;
		printf("LEFT\n");
	}
	else if (keycode == S || keycode == DOWN)
	{
		(*game)->player.curr_y--;
		printf("DOWN\n");
	}
	else if (keycode == D || keycode == RIGHT)
	{
		(*game)->player.curr_x--;
		printf("RIGHT\n");
	}
	return (0);
}