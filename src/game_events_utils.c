/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 21:49:09 by keishii           #+#    #+#             */
/*   Updated: 2024/08/17 23:57:59 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_key_input(int key, t_game *game_init)
{
	exit_program(game_init, key);
	update_map_objects(game_init, key);
	return (0);
}

void	update_map_objects(t_game *game_init, int key)
{
	t_point	p_pos;

	p_pos.x = game_init->player.pos.x;
	p_pos.y = game_init->player.pos.y;
	if (key == W || key == UP)
		move_player(game_init, p_pos, p_pos.x, p_pos.y - 1);
	else if (key == S || key == DOWN)
		move_player(game_init, p_pos, p_pos.x, p_pos.y + 1);
	else if (key == A || key == LEFT)
		move_player(game_init, p_pos, p_pos.x - 1, p_pos.y);
	else if (key == D || key == RIGHT)
		move_player(game_init, p_pos, p_pos.x + 1, p_pos.y);
}

void	move_player(t_game *game_init, t_point p_pos, int x, int y)
{
	if (game_init->map_init.grid[y][x] != '1')
	{
		check_collectible(game_init, x, y);
		check_exit(game_init, x, y);
		if (game_init->map_init.grid[y][x] != 'E')
		{
			game_init->map_init.grid[p_pos.y][p_pos.x] = '0';
			game_init->map_init.grid[y][x] = 'P';
			if (y == p_pos.y - 1)
				game_init->player.pos.y--;
			else if (y == p_pos.y + 1)
				game_init->player.pos.y++;
			else if (x == p_pos.x - 1)
				game_init->player.pos.x--;
			else if (x == p_pos.x + 1)
				game_init->player.pos.x++;
			game_init->game_data.count_movements++;
			ft_printf("Number of movements: %u\n",
				game_init->game_data.count_movements);
		}
	}
}

void	check_collectible(t_game *game_init, int x, int y)
{
	if (game_init->map_init.grid[y][x] == 'C')
		game_init->game_data.count_collectibles--;
}

void	check_exit(t_game *game_init, int x, int y)
{
	int	collectibles_on_map;

	collectibles_on_map = game_init->game_data.count_collectibles;
	if (game_init->map_init.grid[y][x] == 'E' && collectibles_on_map == 0)
	{
		ft_printf("Congratulations!\n");
		ft_printf("You've collected all the keys and found the chest!\n");
		exit_program(game_init, ESC);
	}
}
