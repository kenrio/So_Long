/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:24:33 by keishii           #+#    #+#             */
/*   Updated: 2024/08/15 21:35:52 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_start(t_game *game_init)
{
	mlx_loop_hook(game_init->mlx_ptr, &draw_map, game_init);
	mlx_loop(game_init->mlx_ptr);
}
