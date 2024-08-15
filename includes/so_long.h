/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:41:50 by keishii           #+#    #+#             */
/*   Updated: 2024/08/15 21:10:26 by keishii          ###   ########.fr       */
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

# define CELL_SIZE 64

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
	char	c;
	int		v;
}				t_tile;

typedef struct s_game_resolutions
{
	int		settings_map_width;
	int		settings_map_height;
	char	*settings_name_window;
	char	*settings_name_map;
}				t_game_resolutions;

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

typedef struct s_game_data
{
	int	count_player;
	int	count_exit;
	int	count_collectibles;
	int	exit_access;
	int	collectible_access;
	int	count_movements;
}				t_game_data;

typedef struct s_map_data
{
	char	**grid;
	t_tile	**tile;
	int		width;
	int		height;
}				t_map_data;

typedef struct s_game
{
	void				*mlx_ptr;
	void				*win_ptr;
	t_map_data			map_init;
	t_game_data			game_data;
	t_player			player;
	t_game_objs			game_objs;
	t_game_resolutions	resolution_init;
	void				*img;
}						t_game;

void	initialize_game_struct(t_game *game_init);
void	open_map(t_game *game_init, char *file_path);
void	read_map(t_game *game_init, int fd);
void	fill_grid(t_game *game_init, char *line, t_point grid_pos, int fd);
int		check_map_extension(char *s);
int		count_map_lines(char *file_path);
int		count_map_objects(t_game *game_init);
int		check_map_wall(t_game *game_init);
int		check_map_character(int c);
int		check_map_objects(t_game *game_init);
int		check_map_status(t_game *game_init);
void	check_map_path(t_game *game_init, t_point p_pos);
void	allocate_grid(t_game *game_init, int fd);
void	allocate_line(t_game *game_init, t_point grid_pos, int fd);
void	free_grid_and_tile(t_game *game_init);
void	free_grid(t_game *game_init);
void	free_tile(t_game *game_init);
void	exit_error(char *message);
void	free_and_exit(int fd, t_game *game_init, char *message);
size_t	ft_strlen(char *s);
size_t	ft_linelen(char *s);

void	initialize_game(t_game *game_init);
void	initialize_game_img(t_game *game_init);
void	load_img(t_game *game_init, void **image, char *file_path);
void	game_start(t_game *game_init);
int		draw_map(t_game *game_init);
void	draw_img(t_game *game_init, void *img, int x, int y);
void	free_img(t_game *game_init);

#endif
