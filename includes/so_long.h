/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:41:50 by keishii           #+#    #+#             */
/*   Updated: 2024/08/03 15:02:01 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# include <stdio.h>

# include "mlx.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_point
{
	size_t	x;
	size_t	y;
}				t_point;

typedef struct s_player
{
	t_point	start_pos;
	t_point	pos;
}				t_player;

typedef struct s_tile
{
	char	t;
	int		v;
}				t_tile;

typedef struct s_map
{
	char	*path;
	int		fd;
	size_t	width;
	size_t	height;
	char	**grid;
	t_tile	**tiles;
	int		exit_access;
	int		collectible_access;
}				t_map;

typedef struct s_data
{
	t_map		map;
	t_player	player;
	int			start_found;
	int			exit_found;
	int			collectibles;
	void		*mlx;
	void		*win;
	void		*img;
	void		*textures[5];
}				t_data;

size_t	ft_strlen(char *s);
int		check_map_name(char *s);
void	exit_error(char *message);
void	init_game(t_data *data, char *map_path);
void	parse_map(t_map *map);
size_t	ft_linelen(char *s);
void	fill_map(t_data *data);
void	init_map(t_data *data, t_point *p);
void	allocate_line(t_data *data, t_point grid_pos);
void	fill_tiles(t_data *data, char *line, t_point grid_pos);
int		check_map_wall(t_data *data);
void	free_grid(t_data *data);
void	free_tiles(t_data *data);

#endif