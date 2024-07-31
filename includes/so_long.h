/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:41:50 by keishii           #+#    #+#             */
/*   Updated: 2024/07/31 18:28:18 by keishii          ###   ########.fr       */
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

typedef struct  s_point
{
    size_t  x;
    size_t  y;
}               t_point;

typedef struct  s_tile
{
    char    t;
    int     v;
}               t_tile;

typedef struct s_map
{
    char    *path;
    int     fd;
    size_t  width;
    size_t  height;
    char    **grid;
    t_tile  **tiles;
}               t_map;

typedef struct  s_data
{
    void    *mlx;
    void    *win;
    void    *img;
    void    *textures[5];
    t_map   map;
}               t_data;

size_t  ft_strlen(char *s);
int     check_map_name(char *s);
void    map_error(char *message);
void	init_game(t_data *data, char *map_path);
void	parse_map(t_map *map);
size_t  ft_linelen(char *s);
void	fill_map(t_data *data);
void	init_map(t_data *data, t_point *p);
void	allocate_line(t_data *data, t_point grid_pos);
void	fill_tiles(t_data *data, char *line, t_point grid_pos);

#endif