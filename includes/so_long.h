/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:41:50 by keishii           #+#    #+#             */
/*   Updated: 2024/08/09 13:16:58 by keishii          ###   ########.fr       */
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
	int	x;
	int	y;
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

typedef struct s_game_data
{
	int	count_player;
	int	count_exit;
	int	count_collectibles;
	int	count_movements;
}				t_game_data;

typedef struct s_map_data
{
	char	**grid;
	int		count_lines;
	int		width;
	int		height;
	char	*path;
	int		fd;
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
	t_game_data			game_data;
	t_game_resolutions	resolution_init;
	t_player	player;
	int			start_found;
	int			exit_found;
	int			collectibles;
	void		*img;
}						t_game;

void	game_struct_init(t_game *game_init);
void	open_map(t_game *game_init, char *file_path);
int		check_map_extension(char *s);
int		count_map_lines(char *file_path);
void	read_map(t_game *game_init, int fd);
void	free_grid(t_game *game_init);
int		check_map_width(t_game *game_init);
int		check_map_wall(t_game *data);
int		count_map_objects(t_game *game_init);
int		check_map_objects(t_game *game_init);
size_t	ft_strlen(char *s);
size_t	ft_linelen(char *s);
void	exit_error(char *message);
void	init_game(t_game *data, char *map_path);
void	parse_map(t_map_data *map);
void	fill_map(t_game *data);
void	init_map(t_game *data, t_point *p);
void	allocate_line(t_game *data, t_point grid_pos);
void	fill_tiles(t_game *data, char *line, t_point grid_pos);

#endif