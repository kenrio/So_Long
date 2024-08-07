/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:47:20 by keishii           #+#    #+#             */
/*   Updated: 2024/08/07 21:13:52 by keishii          ###   ########.fr       */
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
	if (count_map_lines(game_init, file_path) < 3)
	{
		close(fd);
		exit_error("Map has too few lines.");
	}
	read_map(game_init, fd);
	close(fd);
	free_grid(game_init);
}

int	count_map_lines(t_game *game_init, char *file_path)
{
	int		fd;
	char	buffer[BUFFER_SIZE];
	ssize_t	n_read;
	int		i;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (0);
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
				game_init->map_init.count_lines++;
	}
	close(fd);
	return (game_init->map_init.count_lines + 1);
}

void	read_map(t_game *game_init, int fd)
{
	int		i;
	char	*line;

	game_init->map_init.grid
		= malloc((game_init->map_init.count_lines + 1) * sizeof(char *));
	if (!game_init->map_init.grid)
	{
		close(fd);
		exit_error("Failed to allocate memory.");
	}
	i = 0;
	while (i <= game_init->map_init.count_lines)
		game_init->map_init.grid[i++] = NULL;
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		game_init->map_init.grid[i++] = line;
		line = get_next_line(fd);
	}
	return ;
}
