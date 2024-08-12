/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:20:59 by keishii           #+#    #+#             */
/*   Updated: 2024/08/12 15:56:08 by keishii          ###   ########.fr       */
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
			{
				game_init->game_data.count_player++;
				game_init->player.start_pos = p;
				game_init->player.pos = p;
			}
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

int	check_map_status(t_game *game_init)
{
	check_map_path(game_init, game_init->player.start_pos);
	if (game_init->game_data.count_collectibles
		!= game_init->game_data.collectible_access)
	{
		ft_printf("Some collectibles are inaccessible.\n");
		return (1);
	}
	else if (game_init->game_data.exit_access == 0)
	{
		ft_printf("The exit is inaccessible.\n");
		return (1);
	}
	return (0);
}

void	check_map_path(t_game *game_init, t_point p_pos)
{
	t_point	map_size;

	map_size.x = game_init->map_init.width;
	map_size.y = game_init->map_init.height;
	if (p_pos.x < 0 || p_pos.y < 0
		|| p_pos.x > map_size.x || p_pos.y > map_size.y
		|| game_init->map_init.grid[p_pos.y][p_pos.x] == '1'
		|| game_init->map_init.tile[p_pos.y][p_pos.x].v == 1)
		return ;
	game_init->map_init.tile[p_pos.y][p_pos.x].v = 1;
	if (game_init->map_init.grid[p_pos.y][p_pos.x] == 'E')
		game_init->game_data.exit_access++;
	else if (game_init->map_init.grid[p_pos.y][p_pos.x] == 'C')
		game_init->game_data.collectible_access++;
	check_map_path(game_init, (t_point){p_pos.x - 1, p_pos.y});
	check_map_path(game_init, (t_point){p_pos.x + 1, p_pos.y});
	check_map_path(game_init, (t_point){p_pos.x, p_pos.y - 1});
	check_map_path(game_init, (t_point){p_pos.x, p_pos.y + 1});
}
