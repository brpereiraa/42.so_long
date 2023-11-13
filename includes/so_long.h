/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunolopes <brunolopes@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 08:23:19 by brunolopes        #+#    #+#             */
/*   Updated: 2023/11/13 03:08:17 by brunolopes       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "./key_map.h"
# include "./assets.h"
# include "../libft/libft.h"
# include <X11/X.h>
# include <fcntl.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int 	width;
	int		height;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_game {
	size_t	rows;
	size_t	columns;
	size_t	start;
	size_t	exit;
	size_t	collectibles;
	char	**map;
}				t_game;

int		close_window(void);
int		key_handler(int keycode);
void	read_map(t_game **game, char *map);
void	cols_size(t_game **game, char *map);
void	rows_size(t_game **game, char *map);
void 	map_verifications(t_game *game);

#endif