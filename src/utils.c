/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:59:59 by keishii           #+#    #+#             */
/*   Updated: 2024/07/30 18:55:15 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_linelen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	return (len);
}

int	check_map_name(char *s)
{
	size_t	i;

	i = ft_strlen(s) - 1;
	if (s[i] == 'r' && s[i - 1] == 'e' && s[i - 2] == 'b' && s[i - 3] == '.')
		return (0);
	return (1);
}

int	check_map_character(int c)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
		return (1);
	return (0);
}

void	map_error(char *message)
{
	ft_printf("\nError: ");
	ft_printf("%s\n\n", message);
	exit(1);
}

void	init_game(t_data *data, char *map_path)
{
	data->map.path = map_path;
}

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

void	fill_tiles(t_data *data, char *line, t_point grid_pos)
{
	data->map.grid[grid_pos.y][grid_pos.x] = line[grid_pos.x];
	data->map.tiles[grid_pos.y][grid_pos.x].t = line[grid_pos.x];
	data->map.tiles[grid_pos.y][grid_pos.x].v = 0;
	if (check_map_character(data->map.grid[grid_pos.y][grid_pos.x]))
		map_error("Unspecified charcter in map file.");
}

void	parse_map(t_map *map)
{
	int		fd;
	char	*line;

	fd = open(map->path, O_RDONLY);
	if (fd < 0)
		map_error("Map file not found.");
	ft_printf("Check file path: valid\n");
	map->height = 0;
	map->width = 0;
	line = get_next_line(fd);
	while (line)
	{
		map->height++;
		if (map->height == 1)
			map->width = ft_linelen(line);
		if (ft_linelen(line) != map->width)
			map_error("Map is not rectangular.");
		ft_printf("%s", line);
		line = get_next_line(fd);
	}
	close(fd);
	if (map->height == 0)
		map_error("Map file is empty.");
	ft_printf("\nCheck map shape: valid\n");
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
		grid_pos.y++;
		line = get_next_line(data->map.fd);
	}
	close(data->map.fd);
	ft_printf("Check map content: valid\n");
}