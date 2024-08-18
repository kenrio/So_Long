/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:50:31 by keishii           #+#    #+#             */
/*   Updated: 2024/08/18 13:41:07 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game_init;

	initialize_game_struct(&game_init);
	if (argc != 2)
		exit_error("Wrong inputs.\nUsage: ./so_long <file_path/filename>.ber");
	open_map(&game_init, argv[1]);
	initialize_game(&game_init);
	game_start(&game_init);
	ft_printf("\nProgram has successfully ended.\n");
	return (0);
}

void	initialize_game_struct(t_game *game_init)
{
	t_game_objs	*objects;

	*game_init = (t_game){0};
	game_init->mlx_ptr = NULL;
	game_init->win_ptr = NULL;
	objects = malloc(sizeof(t_game_objs));
	if (!objects)
		exit_error("Failed to allocate memory.");
	game_init->game_objs = *objects;
	free(objects);
}
