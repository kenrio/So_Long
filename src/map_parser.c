/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:15:15 by keishii           #+#    #+#             */
/*   Updated: 2024/08/11 13:57:47 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(t_map_data *map)
{
	int		fd;
	char	*line;

	fd = open(map->path, O_RDONLY);
	if (fd < 0)
		exit_error("Map file not found.");
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
			exit_error("Map is not rectangular.");
		line = get_next_line(fd);
	}
	close(fd);
	if (map->height == 0)
		exit_error("Map file is empty.");
	ft_printf("Check map shape: OK!\n");
}

void	check_map_status(t_game *data)
{
	if (data->start_found <= 0)
		exit_error("Map has no start point.");
	else if (data->start_found > 1)
		exit_error("Map has multiple start points.");
	else if (data->collectibles <= 0)
		exit_error("Map has no collectibles.");
	else if (data->collectibles != data->map_init.collectible_access)
		exit_error("Some collectibles are inaccessible.");
	else if (data->exit_found <= 0)
		exit_error("Map has no exit.");
	else if (data->exit_found > 1)
		exit_error("Map has multiple exits.");
	else if (data->map_init.exit_access == 0)
		exit_error("The exit is inaccessible.");
}

void	fill_map(t_game *data)
{
	t_point	grid_pos;
	char	*line;

	init_map(data, &grid_pos);
	line = get_next_line(data->map_init.fd);
	while (line)
	{
		allocate_line(data, grid_pos);
		while (grid_pos.x < data->map_init.width)
		{
			fill_tiles(data, line, grid_pos);
			grid_pos.x++;
		}
		grid_pos.x = 0;
		ft_printf("%s\n", data->map_init.grid[grid_pos.y]);
		grid_pos.y++;
		line = get_next_line(data->map_init.fd);
	}
	close(data->map_init.fd);
	printf("%d start point found.\n", data->start_found);
	if (check_map_wall(data))
		exit_error("Map is not surronded by walls.");
	check_map_path(data, data->player.pos);
	printf("%d/%d collectibles accessible.\n", data->map_init.collectible_access, data->collectibles);
	printf("%d/%d exit accessible.\n", data->map_init.exit_access, data->exit_found);
	check_map_status(data);
	// free_grid(data);
	// free_tiles(data);
	ft_printf("Check map content: OK!\n");
}
