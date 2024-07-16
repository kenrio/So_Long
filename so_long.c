/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:52:14 by keishii           #+#    #+#             */
/*   Updated: 2024/07/16 18:53:34 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
    void    *mlx_ptr;

    mlx_ptr = mlx_init();
    if (!mlx_ptr)
        return (1);
    free(mlx_ptr);
    return (0);
}