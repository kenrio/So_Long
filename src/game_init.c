/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:57:16 by keishii           #+#    #+#             */
/*   Updated: 2024/08/13 17:39:39 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_game(t_game *game_init)
{
	game_init->mlx_ptr = mlx_init();
	if (!game_init->mlx_ptr)
		exit_error("Failed to initialize window system (mlx_init()).");
	game_init->win_ptr = mlx_new_window(game_init->mlx_ptr,
		game_init->map_init.width * CELL_SIZE,
		game_init->map_init.height * CELL_SIZE, "So Long");
	if (!game_init->win_ptr)
		exit_error("Failed to initialize new window (mlx_new_window())");
	initialize_game_img(game_init);
}

void	initialize_game_img(t_game *game_init)
{
	load_img(game_init, &game_init->game_objs.floor,
			"./textures/grass.xpm");
	load_img(game_init, &game_init->game_objs.wall,
			"./textures/tree.xpm");
	load_img(game_init, &game_init->game_objs.player,
			"./textures/player.xpm");
	load_img(game_init, &game_init->game_objs.collectibles,
			"./textures/key.xpm");
	load_img(game_init, &game_init->game_objs.exit,
			"./textures/chest.xpm");
}

void	load_img(t_game *game_init, void **image, char *file_path)
{
	int	width;
	int	height;

	*image = mlx_xpm_file_to_image(game_init->mlx_ptr, file_path, &width, &height);
	if (!*image)
	{
		exit_error("Failed to load image.");
	}
}
