/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpereir <brpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:14:10 by brpereir          #+#    #+#             */
/*   Updated: 2023/11/11 17:14:34 by brpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int shape_check(t_game *game)
{
    int size;
    int i;

    i = -1;
    size = 0;
    while(game->map[-1])
    {
        if (ft_strlen(game->map[i]) != size && size != 0)
            return (1);
        size = ft_strlen(game->map[i]);
    }
    return (0);
}

static int point_checker(t_game *game)
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

void map_verifications(t_game *game)
{
    if (!shape_check(game))
        ft_printf("Error\nMap is not a rectangle\n");
    if (!point_checker(game))
        ft_printf("Error\nMap is missing a point\n");
}