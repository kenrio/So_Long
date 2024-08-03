/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:50:31 by keishii           #+#    #+#             */
/*   Updated: 2024/08/03 16:38:54 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q so_long");
// }

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		exit_error("Wrong inputs.\nCheck usage: ./so_long <map name>.ber");
	else if (argc == 2 && check_map_name(argv[1]))
		exit_error("Wrong map name.");
	ft_printf("Check inputs: OK!\n");
	init_game(&data, argv[1]);
	parse_map(&data.map);
	fill_map(&data);
	return (0);
}
