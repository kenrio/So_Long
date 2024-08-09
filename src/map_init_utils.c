/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:20:59 by keishii           #+#    #+#             */
/*   Updated: 2024/08/09 11:00:16 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_width(t_game *game_init)
{
	int		i;
	size_t	width;

	width = ft_linelen(game_init->map_init.grid[0]);
	i = 1;
	while (i < game_init->map_init.height)
	{
		if (width != ft_linelen(game_init->map_init.grid[i]))
			return (1);
		i++;
	}
	game_init->map_init.width = width;
	return (0);
}

int	check_map_wall(t_game *game_init)
{
	t_point	p;

	p.x = 0;
	while (p.x < game_init->map_init.width)
	{
		p.y = 0;
		while (p.y < game_init->map_init.height)
		{
			if (p.x == 0 || p.y == 0 || p.x == game_init->map_init.width - 1
				|| p.y == game_init->map_init.height - 1)
			{
				if (game_init->map_init.grid[p.x][p.y != '1'])
					return (1);
			}
			p.y++;
		}
		p.x++;
	}
	return (0);
}
