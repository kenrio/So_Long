/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:41:50 by keishii           #+#    #+#             */
/*   Updated: 2024/08/07 13:46:19 by keishii          ###   ########.fr       */
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

typedef struct s_game_objs
{
	void	*player;
	void	*collectibles;
	void	*exit;
	void	*wall;
	void	*floor;
	int		img_width;
	int		img_height;
}				t_game_objs;

typedef struct s_game_resolutions
{
	int		settings_map_width;
	int		settings_map_height;
	char	*settings_name_window;
	char	*settings_name_map;
}				t_game_resolutions;

typedef struct s_map_data
{
	char	**grid;
	int		count_lines;
	char	*path;
	int		fd;
	size_t	width;
	size_t	height;
	t_tile	**tiles;
	int		exit_access;
	int		collectible_access;
}				t_map_data;

typedef struct s_game
{
	void				*mlx_ptr;
	void				*win_ptr;
	t_game_objs			game_objs;
	t_map_data			map_init;
	t_game_resolutions	resolution_init;
	t_player	player;
	int			start_found;
	int			exit_found;
	int			collectibles;
	void		*img;
}						t_game;

void	game_struct_init(t_game *game_init);
void	open_map(t_game *game_init, char *file_path);
int		count_map_line(int fd);
size_t	ft_strlen(char *s);
int		check_map_extension(char *s);
void	exit_error(char *message);
void	init_game(t_game *data, char *map_path);
void	parse_map(t_map_data *map);
size_t	ft_linelen(char *s);
void	fill_map(t_game *data);
void	init_map(t_game *data, t_point *p);
void	allocate_line(t_game *data, t_point grid_pos);
void	fill_tiles(t_game *data, char *line, t_point grid_pos);
int		check_map_wall(t_game *data);
void	free_grid(t_game *data);
void	free_tiles(t_game *data);

#endif