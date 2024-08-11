/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:47:20 by keishii           #+#    #+#             */
/*   Updated: 2024/08/11 14:50:51 by keishii          ###   ########.fr       */
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
	free_grid(game_init);
}

int	count_map_lines(char *file_path)
{
	int		fd;
	int		count;
	char	buffer[BUFFER_SIZE];
	ssize_t	n_read;
	int		i;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (0);
	count = 0;
	while (1)
	{
		n_read = read(fd, buffer, BUFFER_SIZE);
		if (n_read < 0)
			return (0);
		else if (n_read == 0)
			break ;
		i = 0;
		while (i < n_read)
			if (buffer[i++] == '\n')
				count++;
	}
	close(fd);
	return (count + 1);
}

void	read_map(t_game *game_init, int fd)
{
	t_point	p;
	char	*line;

	game_init->map_init.grid
		= malloc(game_init->map_init.height * sizeof(char *));
	game_init->map_init.tile
		= (t_tile **)malloc(game_init->map_init.height * sizeof(t_tile *));
	if (!game_init->map_init.grid || !game_init->map_init.tile)
	{
		close(fd);
		exit_error("Failed to allocate memory.");
	}
	p.y = 0;
	line = get_next_line(fd);
	game_init->map_init.width = ft_linelen(line);
	printf("game_init->map_init.height: %d\n", game_init->map_init.height);
	printf("game_init->map_init.width: %d\n", game_init->map_init.width);
	while (p.y < game_init->map_init.height)
	{
		printf("[%d]ft_linelen(line): %zu\n", p.y, ft_linelen(line));
		if (game_init->map_init.width != (int)ft_linelen(line))
		{
			close(fd);
			free_grid(game_init);
			exit_error("Incorrect line width.");
		}
		fill_grid(game_init, line, p);
		free(line);
		p.y++;
		line = get_next_line(fd);
	}
	free(line);
	if (check_map_wall(game_init) || count_map_objects(game_init))
	{
		close(fd);
		free_grid(game_init);
		exit_error("Map is not valid.");
	}
	return ;
}

void	fill_grid(t_game *game_init, char *line, t_point grid_pos)
{
	game_init->map_init.grid[grid_pos.y]
		= malloc((game_init->map_init.width) * sizeof(char));
	game_init->map_init.tile[grid_pos.y]
		= malloc((game_init->map_init.width) * sizeof(t_tile));
	grid_pos.x = 0;
	while (grid_pos.x < game_init->map_init.width)
	{
		game_init->map_init.grid[grid_pos.y][grid_pos.x] = line[grid_pos.x];
		game_init->map_init.tile[grid_pos.y][grid_pos.x].c = line[grid_pos.x];
		grid_pos.x++;
	}
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
			{
				if (game_init->map_init.grid[p.y] == NULL)
					return (1);
				if (game_init->map_init.grid[p.y][p.x] != '1')
					return (1);
			}
			p.x++;
		}
		p.y++;
	}
	return (0);
}
