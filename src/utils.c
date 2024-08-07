/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:59:59 by keishii           #+#    #+#             */
/*   Updated: 2024/08/08 01:07:07 by keishii          ###   ########.fr       */
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

int	check_map_width(t_game *game_init)
{
	int		i;
	size_t	width;

	width = ft_linelen(game_init->map_init.grid[0]);
	i = 1;
	while (i < game_init->map_init.count_lines)
	{
		if (width != ft_linelen(game_init->map_init.grid[i]))
			return (1);
		i++;
	}
	return (0);
}

void	exit_error(char *message)
{
	ft_printf("\nError: ");
	ft_printf("%s\n\n", message);
	exit(1);
}

void	init_game(t_game *data, char *file_path)
{
	data->map_init.path = file_path;
	data->start_found = 0;
	data->exit_found = 0;
	data->collectibles = 0;
	data->map_init.exit_access = 0;
	data->map_init.collectible_access = 0;
}
