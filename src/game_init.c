/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:57:16 by keishii           #+#    #+#             */
/*   Updated: 2024/08/12 18:00:50 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_game(t_game *game_init)
{
	game_init->mlx_ptr = mlx_init();
	if (!game_init->mlx_ptr)
		exit_error("Failed to initialize game (mlx_init()).");
	game_init->win_ptr = mlx_new_window(game_init->mlx_ptr,
		game_init->map_init.width * CELL_SIZE,
		game_init->map_init.height * CELL_SIZE, "So Long");
	if (!game_init->win_ptr)
		exit_error("Failed to initialize game window (mlx_new_window())");
	printf("count_movements: %d\n", game_init->game_data.count_movements);
}