/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 21:49:09 by keishii           #+#    #+#             */
/*   Updated: 2024/08/17 00:21:20 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_key_input(int key, t_game *game_init)
{
	exit_program(game_init, key);
	update_map_objects(game_init, key);
	printf("player pos: (%d, %d)\n", game_init->player.pos.x, game_init->player.pos.y);
	return (0);
}

void	update_map_objects(t_game *game_init, int key)
{
	t_point	p_pos;

	p_pos.x = game_init->player.pos.x;
	p_pos.y = game_init->player.pos.y;
	if (key == W || key == UP)
	{
		if (game_init->map_init.grid[p_pos.y - 1][p_pos.x] != '1')
		{
			game_init->map_init.grid[p_pos.y][p_pos.x] = '0';
			game_init->map_init.grid[p_pos.y - 1][p_pos.x] = 'P';
			game_init->player.pos.y--;
		}
	}
	else if (key == S || key == DOWN)
	{
		if (game_init->map_init.grid[p_pos.y + 1][p_pos.x] != '1')
		{
			game_init->map_init.grid[p_pos.y][p_pos.x] = '0';
			game_init->map_init.grid[p_pos.y + 1][p_pos.x] = 'P';
			game_init->player.pos.y++;
		}
	}
	else if (key == A || key == LEFT)
	{
		if (game_init->map_init.grid[p_pos.y][p_pos.x - 1] != '1')
		{
			game_init->map_init.grid[p_pos.y][p_pos.x] = '0';
			game_init->map_init.grid[p_pos.y][p_pos.x - 1] = 'P';
			game_init->player.pos.x--;
		}
	}
	else if (key == D || key == RIGHT)
	{
		if (game_init->map_init.grid[p_pos.y][p_pos.x + 1] != '1')
		{
			game_init->map_init.grid[p_pos.y][p_pos.x] = '0';
			game_init->map_init.grid[p_pos.y][p_pos.x + 1] = 'P';
			game_init->player.pos.x++;
		}
	}
}
