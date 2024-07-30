/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:14:16 by keishii           #+#    #+#             */
/*   Updated: 2024/05/16 16:37:33 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_putptr_fd(unsigned int p);

int	ft_printf_putptr(unsigned int p)
{
	int			len;

	len = ft_printf_putstr("0x");
	len += ft_putptr_fd(p);
	return (len);
}

static int	ft_putptr_fd(unsigned int p)
{
	int	len;

	len = 0;
	if (p >= 16)
	{
		len += ft_putptr_fd(p / 16);
		ft_putptr_fd(p % 16);
	}
	else if (p <= 9)
		ft_printf_putchar(p + '0');
	else
		ft_printf_putchar(p + 87);
	len++;
	return (len);
}
