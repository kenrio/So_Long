/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:46:52 by keishii           #+#    #+#             */
/*   Updated: 2024/08/14 16:47:15 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(char *message)
{
	ft_printf("\nError: ");
	ft_printf("%s\n\n", message);
	exit(1);
}

void	free_and_exit(int fd, t_game *game_init, char *message)
{
	close(fd);
	free_grid_and_tile(game_init);
	exit_error(message);
}
