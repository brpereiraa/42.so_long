/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunolopes <brunolopes@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:57:11 by marvin            #+#    #+#             */
/*   Updated: 2023/11/11 16:17:47 by brunolopes       ###   ########.fr       */
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
        if ((*game)->map[i][++j] != "\n")
            (*game)->map[i][j] = 0;
    }
}

int shape_check(t_game *game)
{
    int size;
    int i;

    i = -1;
    size = 0;
    while(game->map[-1])
    {
        if (ft_strlen(game->map[i]) != size && size != 0)
            return (0);
        size = ft_strlen(game->map[i]);
    }
    return (1);
}

int point_checker(t_game *game)
{
    int i;
    int j;
    int collectibles;
    int exits;
    int start;

    i = -1;
    while(game->map[++i])
    {
        j = -1;
        while(game->map[i][++j])
        {
            if (game->map[i][j] == 'C')
                collectibles++;
            if (game->map[i][j] == 'E')
                exits++;
            if (game->map[i][j] == 'P')
                start++;
        }
    }
    if (collectibles == 0 || exits != 1 || start != 1)
        return (1);
    return (0);
}
