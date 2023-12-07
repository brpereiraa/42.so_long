/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brpereir <brpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:57:11 by marvin            #+#    #+#             */
/*   Updated: 2023/12/07 17:08:02 by brpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	map_trim(t_game **game)
{
	size_t	i;
	size_t	j;

	i = -1;
	while ((*game)->map[++i])
	{
		j = -1;
		while ((*game)->map[i][++j])
			if ((*game)->map[i][j] == '\n')
				(*game)->map[i][j] = 0;
	}
}

void	read_map(t_game **game, char *map)
{
	size_t	i;
	int		fd;

	fd = open (map, O_RDONLY);
	i = -1;
	(*game)->map = (char **)malloc (sizeof(char *) * ((*game)->rows + 1));
	while (++i < (*game)->rows)
		(*game)->map[i] = get_next_line (fd);
	(*game)->map[i] = NULL;
	close (fd);
	map_trim (game);
}

void	cols_size(t_game **game, char *map)
{
	int		fd;
	char	*str;

	fd = open (map, O_RDONLY);
	if (fd == -1)
		free_game (game, 0);
	str = get_next_line (fd);
	if (!str || !str[0])
	{
		free (str);
		free (*game);
		exit (1);
	}
	(*game)->columns = ft_strlen (str) - 1;
	free (str);
	close (fd);
}

void	rows_size(t_game **game, char *map)
{
	int		fd;
	char	*str;

	(*game)->rows = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	str = get_next_line(fd);
	while (str)
	{
		(*game)->rows++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
}
