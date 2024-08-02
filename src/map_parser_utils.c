/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:19:27 by keishii           #+#    #+#             */
/*   Updated: 2024/08/02 12:05:20 by keishii          ###   ########.fr       */
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
		map_error("Found unspecified character in map file.");
}

int	check_map_wall(t_data *data)
{
	t_point	p;

	p.x = 0;
	p.y = 0;
	while (p.x < data->map.width)
	{
		if (data->map.grid[p.y][p.x] != '1')
			return (1);
		else if (data->map.grid[data->map.height - 1][p.x] != '1')
			return (1);
		p.x++;
	}
	p.x = 0;
	while (p.y < data->map.height)
	{
		if (data->map.grid[p.y][p.x] != '1')
			return (1);
		else if (data->map.grid[p.y][data->map.width - 1] != '1')
			return (1);
		p.y++;
	}
	return (0);
}
