/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunolopes <brunolopes@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 08:23:19 by brunolopes        #+#    #+#             */
/*   Updated: 2023/12/05 17:15:12 by brunolopes       ###   ########.fr       */
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

# define TILES_SIZE 50

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int 	width;
	int		height;
}				t_data;

typedef struct s_image {
	void	*player1;
	void	*wall;
	void	*grass;
	void	*collectible;
	void	*exit;
}				t_image;

typedef struct	s_player {
	size_t	curr_x;
	size_t	curr_y;
	size_t	prev_x;
	size_t	prev_y;
}				t_player;

typedef struct s_game {
	struct	s_player	player;
	struct	s_image		sprites;
	void				*mlx;
	void				*win;
	size_t				rows;
	size_t				columns;
	size_t				start;
	size_t				exit;
	size_t				collectibles;
	char				**map;
}				t_game;

int		close_window(void);
int		key_handler(int keycode, t_game **game);	
void	read_map(t_game **game, char *map);
void	cols_size(t_game **game, char *map);
void	rows_size(t_game **game, char *map);
void 	map_verifications(t_game *game);
void	open_image(t_game **game);
void	get_player(t_game **game);
void	put_image(t_game **game);
void	free_game(t_game **game);
void	free_map(char	**map);


#endif