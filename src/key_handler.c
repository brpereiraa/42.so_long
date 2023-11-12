/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpereir <brpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:34:47 by brpereir          #+#    #+#             */
/*   Updated: 2023/11/12 16:33:34 by brpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(void)
{
	exit(EXIT_SUCCESS);
}

int key_handler(int keycode)
{
	if(keycode == ESC)
		exit(EXIT_SUCCESS);
	else if (keycode == W || keycode == UP)
		printf("UP\n");
	else if (keycode == A || keycode == LEFT)
		printf("LEFT\n");
	else if (keycode == S || keycode == DOWN)
		printf("DOWN\n");
	else if (keycode == D || keycode == RIGHT)
		printf("RIGHT\n");
	return (0);
}