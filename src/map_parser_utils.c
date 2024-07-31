/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:19:27 by keishii           #+#    #+#             */
/*   Updated: 2024/07/31 18:23:48 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_data *data, t_point *p)
{
	data->map.fd = open(data->map.path, O_RDONLY);
	data->map.grid = (char **)malloc(data->map.height * sizeof(char *));
	data->map.tiles = (t_tile **)malloc(data->map.height * sizeof(t_tile *));
	p->x = 0;
	p->y = 0;
}

void	allocate_line(t_data *data, t_point grid_pos)
{
	data->map.grid[grid_pos.y] = (char *)malloc((data->map.width - 1) \
											* sizeof(char));
	data->map.tiles[grid_pos.y] = (t_tile *)malloc((data->map.width - 1) \
											* sizeof(t_tile));
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
		map_error("Unspecified charcter in map file.");
}
