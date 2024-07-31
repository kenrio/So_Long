/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:41:50 by keishii           #+#    #+#             */
/*   Updated: 2024/07/25 15:02:29 by keishii          ###   ########.fr       */
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

typedef struct s_map
{
    char    *path;
    size_t  width;
    size_t  height;
}               t_map ;

typedef struct  s_data
{
    void    *mlx;
    void    *win;
    void    *img;
    void    *textures[5];
    t_map   map;
}               t_data ;

size_t  ft_strlen(char *s);
int     check_map_name(char *s);
void    map_error(char *message);
void	init_game(t_data *data, char *map_path);
void	parse_map(t_map *map);

#endif