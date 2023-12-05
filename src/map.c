/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunolopes <brunolopes@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:57:11 by marvin            #+#    #+#             */
/*   Updated: 2023/12/05 22:36:13 by brunolopes       ###   ########.fr       */
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
	(*game)->map = (char **)malloc(sizeof(char *) * ((*game)->rows + 1));
	while(++i < (*game)->rows)
		(*game)->map[i] = get_next_line(fd);
	(*game)->map[i] = NULL;
    close(fd);
    map_trim(game);
}

void cols_size(t_game **game, char *map)
{
	int	fd;
	char	*str;

	fd = open(map, O_RDONLY);
	if(fd == -1)
		exit(EXIT_FAILURE);
	str = get_next_line(fd);
	if (!str || !str[0])
	{
		free(str);
		free(*game);
		exit(1);
	}
	(*game)->columns = ft_strlen(str);
	free(str);
	close(fd);
} 

void rows_size(t_game **game, char *map)
{
	int	fd;
	char	*str;

	(*game)->rows = 0;
	fd = open(map, O_RDONLY);
	if(fd == -1)
		exit(EXIT_FAILURE);
	while ((str = get_next_line(fd)))
	{
		(*game)->rows++;
		free(str);
	}
	close(fd);
}
