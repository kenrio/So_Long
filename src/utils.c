/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:59:59 by keishii           #+#    #+#             */
/*   Updated: 2024/08/18 14:02:54 by keishii          ###   ########.fr       */
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
	if (!s)
		return (len);
	while (s[len] && s[len] != '\n')
		len++;
	return (len);
}

int	check_map_extension(char *s)
{
	size_t	i;

	i = ft_strlen(s) - 1;
	if (s[i] == 'r' && s[i - 1] == 'e' && s[i - 2] == 'b' && s[i - 3] == '.')
		return (0);
	return (1);
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

void	initialize_tiles(t_game *game_init)
{
	t_point	p;
	t_point	map_size;

	p.y = -1;
	map_size.x = game_init->map_init.width;
	map_size.y = game_init->map_init.height;
	while (++p.y < map_size.y)
	{
		p.x = 0;
		while (p.x < map_size.x)
			game_init->map_init.tile[p.y][p.x++].v = 0;
	}
}
