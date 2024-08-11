/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:51:24 by keishii           #+#    #+#             */
/*   Updated: 2024/08/12 02:05:35 by keishii          ###   ########.fr       */
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
			free(game_init->map_init.grid[i++]);
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
			free(game_init->map_init.tile[i++]);
	free(game_init->map_init.tile);
	game_init->map_init.tile = NULL;
}

void	free_grid_and_tile(t_game *game_init)
{
	free_grid(game_init);
	free_tile(game_init);
}
