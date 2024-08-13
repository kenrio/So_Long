/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:50:31 by keishii           #+#    #+#             */
/*   Updated: 2024/08/13 00:04:15 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game_init;

	game_init = (t_game){0};
	if (argc != 2)
		exit_error("Wrong inputs.\nUsage: ./so_long <file_path/filename>.ber");
	open_map(&game_init, argv[1]);
	initialize_game(&game_init);
	mlx_loop(game_init.mlx_ptr);
	ft_printf("\nProgram has successfully ended.\n");
	return (0);
}
