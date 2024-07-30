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
# include <math.h>

# include <stdio.h>

# include "mlx.h"
# include "ft_printf.h"

typedef struct  s_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    void    *textures[5];
    // t_map   *map;
}               t_data;

size_t  ft_strlen(char *s);
int     check_map_name(char *s);
void    map_error(char *message);

#endif