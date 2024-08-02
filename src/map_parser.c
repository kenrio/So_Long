/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:15:15 by keishii           #+#    #+#             */
/*   Updated: 2024/08/02 15:11:29 by keishii          ###   ########.fr       */
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
		line = get_next_line(fd);
	}
	close(fd);
	if (map->height == 0)
		map_error("Map file is empty.");
	ft_printf("Check map shape: OK!\n");
}

void	check_map_path(t_data *data, t_point p_pos)
{
	t_point	map_size;

	map_size.x = data->map.width;
	map_size.y = data->map.height;
	if (p_pos.x < 0 || p_pos.y < 0 || \
		p_pos.x > map_size.x || p_pos.y > map_size.y || \
		data->map.grid[p_pos.y][p_pos.x] == '1' || \
		data->map.tiles[p_pos.y][p_pos.x].v == 1)
		return ;
	data->map.tiles[p_pos.y][p_pos.x].v = 1;
	if (data->map.grid[p_pos.y][p_pos.x] == 'E')
		data->map.exit_access = 1;
	else if (data->map.grid[p_pos.y][p_pos.x] == 'C')
		data->map.collectible_access++;
	check_map_path(data, (t_point){p_pos.x - 1, p_pos.y});
	check_map_path(data, (t_point){p_pos.x + 1, p_pos.y});
	check_map_path(data, (t_point){p_pos.x, p_pos.y - 1});
	check_map_path(data, (t_point){p_pos.x, p_pos.y + 1});
	return ;
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
	printf("%d start point found: (%zu, %zu).\n", data->start_found, data->player.start_pos.x, data->player.start_pos.y);
	printf("%d exit found.\n", data->exit_found);
	printf("%d collectibles found.\n", data->collectibles);
	if (check_map_wall(data))
		map_error("Map is not surronded by walls.");
	check_map_path(data, data->player.pos);
	printf("%d exit accessible.\n", data->map.exit_access);
	printf("%d collectibles accessible.\n", data->map.collectible_access);
	ft_printf("Check map content: OK!\n");
}
