/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpereir <brpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:14:10 by brpereir          #+#    #+#             */
/*   Updated: 2023/11/24 12:18:33 by brpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int shape_check(t_game *game)
{
    int size;
    int i;

    i = -1;
    size = -1;
    while(game->map[++i])
    {
        if (ft_strlen(game->map[i]) != size && size != -1)
            return (1);
        size = ft_strlen(game->map[i]);
    }
    return (0);
}

static int point_checker(t_game **game)
{
    int i;
    int j;

    i = -1;
    while((*game)->map[++i])
    {
        j = -1;
        while((*game)->map[i][++j])
        {
            if ((*game)->map[i][j] == 'C')
                (*game)->collectibles++;
            if ((*game)->map[i][j] == 'E')
                (*game)->exit++;
            if ((*game)->map[i][j] == 'P')
                (*game)->start++;
        }
    }
    if ((*game)->collectibles == 0 || (*game)->exit != 1 || (*game)->start++ != 1)
        return (1);
    return (0);
}

void map_verifications(t_game *game)
{
    if (shape_check(game))
    {
        ft_printf("Error:\nMap is not a rectangle\n");
        exit (1);
    }
    if (point_checker(&game))
    {
        ft_printf("Error:\nMap is missing a point\n");
        exit (1);
    }
}
