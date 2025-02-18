/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:47:20 by keishii           #+#    #+#             */
/*   Updated: 2024/08/18 15:36:25 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_map(t_game *game_init, char *file_path)
{
	int	fd;

	if (check_map_extension(file_path))
		exit_error("File extension is incorrect.");
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		exit_error("Could not open file.");
	game_init->map_init.height = count_map_lines(file_path);
	if (game_init->map_init.height < 3)
	{
		close(fd);
		exit_error("Map has too few lines.");
	}
	read_map(game_init, fd);
	close(fd);
}

void	read_map(t_game *game_init, int fd)
{
	t_point	p;
	char	*line;

	allocate_grid(game_init, fd);
	p.y = 0;
	line = get_next_line(fd);
	game_init->map_init.width = ft_linelen(line);
	while (p.y < game_init->map_init.height)
	{
		if (game_init->map_init.width != (int)ft_linelen(line))
		{
			free(line);
			free_and_exit(fd, game_init, "Incorrect line width.");
		}
		fill_grid(game_init, line, p, fd);
		p.y++;
		line = get_next_line(fd);
	}
	free(line);
	if (check_map_wall(game_init) || count_map_objects(game_init)
		|| check_map_status(game_init))
		free_and_exit(fd, game_init, "Map is not valid.");
}

void	fill_grid(t_game *game_init, char *line, t_point grid_pos, int fd)
{
	allocate_line(game_init, grid_pos, fd);
	grid_pos.x = 0;
	while (grid_pos.x < game_init->map_init.width)
	{
		game_init->map_init.grid[grid_pos.y][grid_pos.x] = line[grid_pos.x];
		game_init->map_init.tile[grid_pos.y][grid_pos.x].c = line[grid_pos.x];
		grid_pos.x++;
	}
	free(line);
}

int	check_map_wall(t_game *game_init)
{
	t_point	p;

	p.y = 0;
	while (p.y < game_init->map_init.height)
	{
		p.x = 0;
		while (p.x < game_init->map_init.width)
		{
			if (p.x == 0 || p.y == 0 || p.x == game_init->map_init.width - 1
				|| p.y == game_init->map_init.height - 1)
				if (game_init->map_init.grid[p.y][p.x] != '1')
					return (1);
			p.x++;
		}
		p.y++;
	}
	return (0);
}

int	count_map_objects(t_game *game_init)
{
	t_point	p;

	p.x = 0;
	while (p.x < game_init->map_init.width)
	{
		p.y = 0;
		while (p.y < game_init->map_init.height)
		{
			if (check_map_character(game_init->map_init.grid[p.y][p.x]))
				return (1);
			if (game_init->map_init.grid[p.y][p.x] == 'P')
			{
				game_init->game_data.count_player++;
				game_init->player.start_pos = p;
				game_init->player.pos = p;
			}
			else if (game_init->map_init.grid[p.y][p.x] == 'E')
				game_init->game_data.count_exit++;
			else if (game_init->map_init.grid[p.y][p.x] == 'C')
				game_init->game_data.count_collectibles++;
			p.y++;
		}
		p.x++;
	}
	return (check_map_objects(game_init));
}
