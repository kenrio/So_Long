/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_puthex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:06:55 by keishii           #+#    #+#             */
/*   Updated: 2024/05/15 20:26:08 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_printf_puthex(unsigned int n, const char format)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_printf_puthex(n / 16, format);
		ft_printf_puthex(n % 16, format);
	}
	else if (n <= 9)
		ft_printf_putchar(n + '0');
	else if (format == 'x')
		ft_printf_putchar(n + 87);
	else if (format == 'X')
		ft_printf_putchar(n + 55);
	len++;
	return (len);
}
