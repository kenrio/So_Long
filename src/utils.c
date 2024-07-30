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
	while (*(s++))
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

void	map_error(char *message)
{
	ft_printf("\nError\n\n");
	ft_printf("%s\n\n", message);
	exit(1);
}

void	init_game(t_data *data, char *map_path)
{
	data->map.path = map_path;
}

void	parse_map(t_map *map)
{
	int	fd;

	fd = open(map->path, O_RDONLY);
	if (fd < 0)
		map_error("Map not found.");
	ft_printf("Map found.\n");
	map->height = 0;
	map->width = 0;
}