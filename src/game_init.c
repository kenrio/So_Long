/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:57:16 by keishii           #+#    #+#             */
/*   Updated: 2024/08/12 17:38:35 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_game(t_game *game_init)
{
	game_init->mlx_ptr = mlx_init();
	if (!game_init->mlx_ptr)
		exit_error("Failed to initialize game (mlx_init()).");
}