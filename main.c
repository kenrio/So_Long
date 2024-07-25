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

int	main(int argc, char **argv)
{
	if (argc != 2)
		map_error("\nWrong inputs.\nCheck usage: ./so_long <map name>.ber\n\n");
	else if (argc == 2 && check_map_name(argv[1]))
		map_error("\nWrong map name.\n\n");
	printf("\nMap name is valid.\n\n");
	return (0);
}
