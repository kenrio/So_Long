/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:50:31 by keishii           #+#    #+#             */
/*   Updated: 2024/08/07 12:26:19 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game_init;

	game_struct_init(&game_init);
	if (argc != 2)
		exit_error("Wrong inputs.\nCheck usage: ./so_long <filename>.ber");
	else if (argc == 2 && check_map_name(argv[1]))
		exit_error("Wrong map name.");
	ft_printf("Check inputs: OK!\n");
	init_game(&game_init, argv[1]);
	parse_map(&game_init.map_init);
	fill_map(&game_init);
	return (0);
}

void	game_struct_init(t_game *game_init)
{
	*game_init = (t_game){0};
	return ;
}
