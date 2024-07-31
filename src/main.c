/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:50:31 by keishii           #+#    #+#             */
/*   Updated: 2024/07/25 15:03:50 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

__attribute__((destructor))
static void destructor() {
    system("leaks -q so_long");
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		map_error("Wrong inputs.\nCheck usage: ./so_long <map name>.ber");
	else if (argc == 2 && check_map_name(argv[1]))
		map_error("Wrong map name.");
	ft_printf("Check inputs: valid\n");
	init_game(&data, argv[1]);
	parse_map(&data.map);
	return (0);
}
