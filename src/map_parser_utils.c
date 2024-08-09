/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:19:27 by keishii           #+#    #+#             */
/*   Updated: 2024/08/09 13:17:19 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_data *data, t_point *p)
{
	data->map.fd = open(data->map.path, O_RDONLY);
	data->map.grid = (char **)malloc(data->map.height * sizeof(char *));
	if (!data->map.grid)
		exit_error("Failed to allocate memory.");
	data->map.tiles = (t_tile **)malloc(data->map.height * sizeof(t_tile *));
	if (!data->map.grid)
		exit_error("Failed to allocate memory.");
	p->x = 0;
	p->y = 0;
}

void	allocate_line(t_data *data, t_point grid_pos)
{
	data->map.grid[grid_pos.y] = (char *)malloc((data->map.width - 1) \
											* sizeof(char));
	if (!data->map.grid[grid_pos.y])
		exit_error("Failed to allocate memory.");
	data->map.tiles[grid_pos.y] = (t_tile *)malloc((data->map.width - 1) \
											* sizeof(t_tile));
	if (!data->map.tiles[grid_pos.y])
		exit_error("Failed to allocate memory.");
}

int	check_map_character(int c)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
		return (1);
	return (0);
}

void	fill_tiles(t_data *data, char *line, t_point grid_pos)
{
	data->map.grid[grid_pos.y][grid_pos.x] = line[grid_pos.x];
	data->map.tiles[grid_pos.y][grid_pos.x].t = line[grid_pos.x];
	data->map.tiles[grid_pos.y][grid_pos.x].v = 0;
	if (check_map_character(data->map.grid[grid_pos.y][grid_pos.x]))
	{
		// close(data->map.fd);
		// free_tiles(data);
		// free_grid(data);
		// free(line);
		exit_error("Found unspecified character in map file.");
	}
	else if (data->map.grid[grid_pos.y][grid_pos.x] == 'P')
	{
		data->start_found++;
		data->player.start_pos = grid_pos;
		data->player.pos = grid_pos;
	}
	else if (data->map.grid[grid_pos.y][grid_pos.x] == 'E')
		data->exit_found++;
	else if (data->map.grid[grid_pos.y][grid_pos.x] == 'C')
		data->collectibles++;
}
