/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:51:24 by keishii           #+#    #+#             */
/*   Updated: 2024/08/09 21:49:44 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_grid(t_game *game_init)
{
	int	i;

	if (!game_init->map_init.grid || !game_init->map_init.tile)
		return ;
	i = 0;
	while (i < game_init->map_init.height)
	{
		if (game_init->map_init.grid[i])
			free(game_init->map_init.grid[i]);
		if (game_init->map_init.tile[i])
			free(game_init->map_init.tile[i]);
		i++;
	}
	free(game_init->map_init.grid);
	free(game_init->map_init.tile);
	game_init->map_init.grid = NULL;
	game_init->map_init.tile = NULL;
	return ;
}
