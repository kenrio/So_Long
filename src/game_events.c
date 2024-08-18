/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:24:33 by keishii           #+#    #+#             */
/*   Updated: 2024/08/18 16:45:14 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_start(t_game *game_init)
{
	mlx_hook(game_init->win_ptr, 17, 0L, &close_window, game_init);
	mlx_key_hook(game_init->win_ptr, &check_key_input, game_init);
	mlx_loop_hook(game_init->mlx_ptr, &draw_map, game_init);
	mlx_loop(game_init->mlx_ptr);
}
