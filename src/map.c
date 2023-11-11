/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunolopes <brunolopes@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:48:52 by brunolopes        #+#    #+#             */
/*   Updated: 2023/10/31 20:36:31 by brunolopes       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void ft_check_cols(t_game **game, int fd)
{
	while(get_next_line(fd))
		(*game)->columns++;
} 
