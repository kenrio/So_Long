/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:51:24 by keishii           #+#    #+#             */
/*   Updated: 2024/08/03 15:01:25 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_grid(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->map.height)
	{
		free(data->map.grid[i]);
		data->map.grid[i] = NULL;
		i++;
	}
	free(data->map.grid);
	data->map.grid = NULL;
}

void	free_tiles(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->map.height)
	{
		free(data->map.tiles[i]);
		data->map.tiles[i] = NULL;
		i++;
	}
	free(data->map.tiles);
	data->map.tiles = NULL;
}