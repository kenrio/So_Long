/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:51:24 by keishii           #+#    #+#             */
/*   Updated: 2024/08/07 17:09:18 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_grid(t_game *game_init)
{
	int	i;

	if (!game_init->map_init.grid)
		return ;
	i = 0;
	while (game_init->map_init.grid[i])
	{
		free(game_init->map_init.grid[i]);
		i++;
	}
	free(game_init->map_init.grid);
	game_init->map_init.grid = NULL;
	return ;
}

void	free_tiles(t_game *data)
{
	size_t	i;

	i = 0;
	while (i < data->map_init.height)
	{
		free(data->map_init.tiles[i]);
		data->map_init.tiles[i] = NULL;
		i++;
	}
	free(data->map_init.tiles);
	data->map_init.tiles = NULL;
}