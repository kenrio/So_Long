/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putuint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:00:40 by keishii           #+#    #+#             */
/*   Updated: 2024/05/15 17:59:11 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_putuint_fd(unsigned int n);

int	ft_printf_putuint(unsigned int n)
{
	int				len;
	unsigned int	tmp;

	len = 0;
	tmp = n;
	if (n == 0)
		len = 1;
	while (tmp > 0)
	{
		tmp /= 10;
		len++;
	}
	ft_putuint_fd(n);
	return (len);
}

static void	ft_putuint_fd(unsigned int n)
{
	if (n >= 10)
	{
		ft_putuint_fd(n / 10);
		ft_printf_putchar(n % 10 + '0');
	}
	else
		ft_printf_putchar(n + '0');
}
