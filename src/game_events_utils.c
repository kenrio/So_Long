/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 21:49:09 by keishii           #+#    #+#             */
/*   Updated: 2024/08/16 11:17:13 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_key_input(int key, t_game *game_init)
{
	printf("key: %d\n", key);
	exit_program(game_init, key);
	return (0);
}

int	exit_program(t_game *game_init, int key)
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
	return (0);
}
