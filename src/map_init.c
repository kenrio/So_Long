/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:47:20 by keishii           #+#    #+#             */
/*   Updated: 2024/08/07 14:09:07 by keishii          ###   ########.fr       */
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
	game_init->map_init.count_lines = count_map_line(fd);
	if (!game_init->map_init.count_lines || game_init->map_init.count_lines < 3)
	{
		close(fd);
		exit_error("Map has too few lines.");
	}
}

int	count_map_line(int fd)
{
	int		count;
	char	buffer[BUFFER_SIZE];
	ssize_t	n_read;
	int		i;

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
		{
			if (buffer[i] == '\n')
				count++;
			i++;
		}
	}
	count++;
	return (count);
}
