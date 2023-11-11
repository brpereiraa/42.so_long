/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpereir <brpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:57:11 by marvin            #+#    #+#             */
/*   Updated: 2023/11/11 19:38:35 by brpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void ft_check_cols(t_game **game, int fd)
{
	while(get_next_line(fd))
		(*game)->columns++;
} 
void map_trim(t_game **game)
{
    int i;
    int j;

    i = -1;
    while((*game)->map[++i])
    {
        j = -1;
        if ((*game)->map[i][++j] != '\n')
            (*game)->map[i][j] = 0;
    }
}

void read_map(int fd, t_game **game)
{
	int	i;

	i = -1;
	(*game)->map = (char **)malloc((sizeof(char *) * (*game)->columns) + 1);
	while(++i < (*game)->columns)
		(*game)->map[i] = get_next_line(fd);
}
