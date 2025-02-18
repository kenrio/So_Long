/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:46:52 by keishii           #+#    #+#             */
/*   Updated: 2024/08/18 16:45:08 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(char *message)
{
	ft_printf("\nError:\n");
	ft_printf("%s\n\n", message);
	exit(1);
}

void	free_and_exit(int fd, t_game *game_init, char *message)
{
	close(fd);
	get_next_line(-1);
	free_grid_and_tile(game_init);
	exit_error(message);
}

void	exit_program(t_game *game_init, int key)
{
	if (key == ESC)
	{
		free_img(game_init);
		free_grid_and_tile(game_init);
		mlx_destroy_window(game_init->mlx_ptr, game_init->win_ptr);
		mlx_destroy_display(game_init->mlx_ptr);
		free(game_init->mlx_ptr);
		ft_printf("Exiting program.\n");
		exit(1);
	}
}

int	close_window(t_game *game_init)
{
	exit_program(game_init, ESC);
	return (0);
}
