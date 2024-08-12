/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:12:09 by keishii           #+#    #+#             */
/*   Updated: 2024/08/12 14:47:19 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	allocate_grid(t_game *game_init, int fd)
{
	int	i;

	i = 0;
	game_init->map_init.grid
		= (char **)malloc(game_init->map_init.height * sizeof(char *));
	game_init->map_init.tile
		= (t_tile **)malloc(game_init->map_init.height * sizeof(t_tile *));
	if (!game_init->map_init.grid || !game_init->map_init.tile)
	{
		close(fd);
		exit_error("Failed to allocate memory.");
	}
	while (i < game_init->map_init.height)
	{
		game_init->map_init.grid[i] = NULL;
		game_init->map_init.tile[i] = NULL;
		i++;
	}
}

void	allocate_line(t_game *game_init, t_point grid_pos, int fd)
{
	game_init->map_init.grid[grid_pos.y]
		= malloc((game_init->map_init.width) * sizeof(char));
	game_init->map_init.tile[grid_pos.y]
		= malloc((game_init->map_init.width) * sizeof(t_tile));
	if (!game_init->map_init.grid[grid_pos.y]
		|| !game_init->map_init.tile[grid_pos.y])
	{
		close(fd);
		free_grid_and_tile(game_init);
		exit_error("Failed to allocate memory.");
	}
}
