/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunolopes <brunolopes@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 08:23:19 by brunolopes        #+#    #+#             */
/*   Updated: 2023/10/31 19:51:21 by brunolopes       ###   ########.fr       */
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
	size_t rows;
	size_t columns;
	char	**map;
}				t_game;

void ft_check_cols(t_game **game, int fd);	

#endif