/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpereir <brpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:57:11 by marvin            #+#    #+#             */
/*   Updated: 2023/12/05 10:01:08 by brpereir         ###   ########.fr       */
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
	(*game)->map = (char **)malloc(sizeof(char *) * (*game)->rows + 1);
	while(++i < (*game)->rows)
		(*game)->map[i] = get_next_line(fd);
	(*game)->map[i] = NULL;
    close(fd);
    map_trim(game);
}

void cols_size(t_game **game, char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if(fd == -1)
		exit(EXIT_FAILURE);
	(*game)->columns = ft_strlen(get_next_line(fd)) - 1;
	close(fd);
} 

void rows_size(t_game **game, char *map)
{
	int	fd;

	(*game)->rows = 0;
	fd = open(map, O_RDONLY);
	if(fd == -1)
		exit(EXIT_FAILURE);
	while (get_next_line(fd))
		(*game)->rows++;
	close(fd);
}
