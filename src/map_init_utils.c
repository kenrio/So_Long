/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:20:59 by keishii           #+#    #+#             */
/*   Updated: 2024/08/09 14:38:52 by keishii          ###   ########.fr       */
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
		{
			ft_printf("Incorrect line width.\n");
			return (1);
		}
		i++;
	}
	game_init->map_init.width = width;
	return (0);
}

int	check_map_wall(t_game *game_init)
{
	t_point	p;

	p.y = 0;
	while (p.y < game_init->map_init.height)
	{
		p.x = 0;
		while (p.x < game_init->map_init.width)
		{
			if (p.x == 0 || p.y == 0 || p.x == game_init->map_init.width - 1
				|| p.y == game_init->map_init.height - 1)
			{
				if (game_init->map_init.grid[p.y][p.x] != '1')
				{
					ft_printf("Unclosed wall.\n");
					return (1);
				}
			}
			p.x++;
		}
		p.y++;
	}
	return (0);
}

int	count_map_objects(t_game *game_init)
{
	t_point	p;

	p.x = 0;
	while (p.x < game_init->map_init.width)
	{
		p.y = 0;
		while (p.y < game_init->map_init.height)
		{
			if (check_map_character(game_init->map_init.grid[p.y][p.x]))
				return (1);
			if (game_init->map_init.grid[p.y][p.x] == 'P')
				game_init->game_data.count_player++;
			else if (game_init->map_init.grid[p.y][p.x] == 'E')
				game_init->game_data.count_exit++;
			else if (game_init->map_init.grid[p.y][p.x] == 'C')
				game_init->game_data.count_collectibles++;
			p.y++;
		}
		p.x++;
	}
	return (check_map_objects(game_init));
}

int	check_map_character(int c)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
	{
		ft_printf("Found unspecified chararter.\n");
		return (1);
	}
	return (0);
}

int	check_map_objects(t_game *game_init)
{
	if (!(game_init->game_data.count_player == 1
			&& game_init->game_data.count_exit == 1
			&& game_init->game_data.count_collectibles >= 1))
	{
		ft_printf("Incorrect number of objects.\n");
		return (1);
	}
	return (0);
}
