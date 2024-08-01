/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:15:15 by keishii           #+#    #+#             */
/*   Updated: 2024/08/01 11:30:23 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(t_map *map)
{
	int		fd;
	char	*line;

	fd = open(map->path, O_RDONLY);
	if (fd < 0)
		map_error("Map file not found.");
	ft_printf("Check file path: OK!\n");
	map->height = 0;
	map->width = 0;
	line = get_next_line(fd);
	while (line)
	{
		map->height++;
		if (map->height == 1)
			map->width = ft_linelen(line);
		if (ft_linelen(line) != (size_t)map->width)
			map_error("Map is not rectangular.");
		ft_printf("%s", line);
		line = get_next_line(fd);
	}
	close(fd);
	if (map->height == 0)
		map_error("Map file is empty.");
	ft_printf("\nCheck map shape: OK!\n");
}

void	fill_map(t_data *data)
{
	t_point	grid_pos;
	char	*line;

	init_map(data, &grid_pos);
	line = get_next_line(data->map.fd);
	while (line)
	{
		allocate_line(data, grid_pos);
		while (grid_pos.x < data->map.width)
		{
			fill_tiles(data, line, grid_pos);
			grid_pos.x++;
		}
		grid_pos.x = 0;
		ft_printf("%s\n", data->map.grid[grid_pos.y]);
		grid_pos.y++;
		line = get_next_line(data->map.fd);
	}
	close(data->map.fd);
	if (check_map_wall(data))
		map_error("Map is not surronded by walls.");
	ft_printf("Check map content: OK!\n");
}
