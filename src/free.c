/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:51:24 by keishii           #+#    #+#             */
/*   Updated: 2024/08/15 21:10:15 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_grid(t_game *game_init)
{
	int	i;

	if (!game_init->map_init.grid)
		return ;
	i = 0;
	while (i < game_init->map_init.height)
	{
		if (game_init->map_init.grid[i])
			free(game_init->map_init.grid[i]);
		i++;
	}
	free(game_init->map_init.grid);
	game_init->map_init.grid = NULL;
}

void	free_tile(t_game *game_init)
{
	int	i;

	if (!game_init->map_init.tile)
		return ;
	i = 0;
	while (i < game_init->map_init.height)
	{
		if (game_init->map_init.tile[i])
			free(game_init->map_init.tile[i]);
		i++;
	}
	free(game_init->map_init.tile);
	game_init->map_init.tile = NULL;
}

void	free_grid_and_tile(t_game *game_init)
{
	free_grid(game_init);
	free_tile(game_init);
}

void	free_img(t_game *game_init)
{
	if (game_init->game_objs.floor)
		mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.floor);
	else if (game_init->game_objs.wall)
		mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.wall);
	else if (game_init->game_objs.player)
		mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.player);
	else if (game_init->game_objs.collectibles)
		mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.collectibles);
	else if (game_init->game_objs.exit)
		mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.exit);
	game_init->game_objs = (t_game_objs){0};
}
