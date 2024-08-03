/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:59:59 by keishii           #+#    #+#             */
/*   Updated: 2024/08/03 14:13:07 by keishii          ###   ########.fr       */
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

void	exit_error(char *message)
{
	ft_printf("\nError: ");
	ft_printf("%s\n\n", message);
	exit(1);
}

void	init_game(t_data *data, char *file_path)
{
	data->map.path = file_path;
	data->start_found = 0;
	data->exit_found = 0;
	data->collectibles = 0;
	data->map.exit_access = 0;
	data->map.collectible_access = 0;
}
