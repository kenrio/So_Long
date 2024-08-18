/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:41:20 by keishii           #+#    #+#             */
/*   Updated: 2024/08/18 01:18:16 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_map(t_game *game_init)
{
	t_point	p;

	p.y = -1;
	while (++p.y < game_init->map_init.height)
	{
		p.x = 0;
		while (p.x < game_init->map_init.width)
		{
			if (game_init->map_init.grid[p.y][p.x] == '0')
				draw_img(game_init, game_init->game_objs.floor, p.x, p.y);
			else if (game_init->map_init.grid[p.y][p.x] == '1')
				draw_img(game_init, game_init->game_objs.wall, p.x, p.y);
			else if (game_init->map_init.grid[p.y][p.x] == 'P')
				draw_img(game_init, game_init->game_objs.player,
					game_init->player.pos.x, game_init->player.pos.y);
			else if (game_init->map_init.grid[p.y][p.x] == 'C')
				draw_img(game_init, game_init->game_objs.collectibles,
					p.x, p.y);
			else if (game_init->map_init.grid[p.y][p.x] == 'E')
				draw_img(game_init, game_init->game_objs.exit, p.x, p.y);
			p.x++;
		}
	}
	return (0);
}

void	draw_img(t_game *game_init, void *img, int x, int y)
{
	mlx_put_image_to_window(game_init->mlx_ptr, game_init->win_ptr, img,
		x * CELL_SIZE, y * CELL_SIZE);
}
