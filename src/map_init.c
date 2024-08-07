/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:47:20 by keishii           #+#    #+#             */
/*   Updated: 2024/08/08 01:06:57 by keishii          ###   ########.fr       */
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
	game_init->map_init.count_lines = count_map_lines(file_path);
	if (game_init->map_init.count_lines < 3)
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
	int		i;
	char	*line;

	game_init->map_init.grid
		= malloc(game_init->map_init.count_lines * sizeof(char *));
	if (!game_init->map_init.grid)
	{
		close(fd);
		exit_error("Failed to allocate memory.");
	}
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		game_init->map_init.grid[i++] = line;
		line = get_next_line(fd);
	}
	if (check_map_width(game_init))
	{
		close(fd);
		free_grid(game_init);
		exit_error("Map is not rectangular.");
	}
	return ;
}
