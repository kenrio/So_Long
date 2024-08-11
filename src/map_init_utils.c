/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:20:59 by keishii           #+#    #+#             */
/*   Updated: 2024/08/11 17:52:10 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	check_map_width(t_game *game_init)
{
	int		i;

	i = 0;
	while (i < game_init->map_init.height)
	{
		printf("width[%d]: %zu\n", i, ft_linelen(game_init->map_init.grid[i]));
		if (game_init->map_init.width
			!= (int)ft_linelen(game_init->map_init.grid[i]))
		{
			ft_printf("Incorrect line width.\n");
			return (1);
		}
		i++;
	}
	return (0);
}

// int	check_map_path(t_game *data, t_point p_pos)
// {
// 	t_point	map_size;

// 	map_size.x = data->map_init.width;
// 	map_size.y = data->map_init.height;
// 	if (p_pos.x > map_size.x || p_pos.y > map_size.y ||
// 		data->map_init.grid[p_pos.y][p_pos.x] == '1' ||
// 		data->map_init.v[p_pos.y][p_pos.x].v == 1)
// 		return (1);
// 	data->map_init.tiles[p_pos.y][p_pos.x].v = 1;
// 	if (data->map_init.grid[p_pos.y][p_pos.x] == 'E')
// 		data->map_init.exit_access = 1;
// 	else if (data->map_init.grid[p_pos.y][p_pos.x] == 'C')
// 		data->map_init.collectible_access++;
// 	check_map_path(data, (t_point){p_pos.x - 1, p_pos.y});
// 	check_map_path(data, (t_point){p_pos.x + 1, p_pos.y});
// 	check_map_path(data, (t_point){p_pos.x, p_pos.y - 1});
// 	check_map_path(data, (t_point){p_pos.x, p_pos.y + 1});
// }
