/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:50:31 by keishii           #+#    #+#             */
/*   Updated: 2024/08/11 13:33:09 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game_init;

	game_struct_init(&game_init);
	if (argc != 2)
		exit_error("Wrong inputs.\nUsage: ./so_long <file_path/filename>.ber");
	ft_printf("Check input count: OK!\n");
	open_map(&game_init, argv[1]);
	ft_printf("\nProgram has successfully ended.\n");
	return (0);
}

void	game_struct_init(t_game *game_init)
{
	*game_init = (t_game){0};
	return ;
}
