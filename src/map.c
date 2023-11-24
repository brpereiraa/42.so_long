/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunolopes <brunolopes@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:57:11 by marvin            #+#    #+#             */
/*   Updated: 2023/11/21 15:16:37 by brunolopes       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void map_trim(t_game **game)
{
    int i;
    int j;

    i = -1;
    while((*game)->map[++i])
    {
        j = -1;
		while((*game)->map[i][++j])
			if ((*game)->map[i][j] == '\n')
          		(*game)->map[i][j] = 0;
    }
}

void read_map(t_game **game, char *map)
{
	int	i;
    int fd;

    fd = open(map, O_RDONLY);
	i = -1;
	(*game)->map = (char **)malloc(sizeof(char *) * (*game)->columns + 1);
	while(++i < (*game)->columns)
		(*game)->map[i] = get_next_line(fd);
	(*game)->map[i] = NULL;
    close(fd);
    map_trim(game);
}

void cols_size(t_game **game, char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	(*game)->rows = ft_strlen(get_next_line(fd));
	close(fd);
} 

void rows_size(t_game **game, char *map)
{
	int	fd;

	(*game)->columns = 0;
	fd = open(map, O_RDONLY);
	while (get_next_line(fd))
		(*game)->columns++;
	close(fd);
}
