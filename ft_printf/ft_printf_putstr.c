/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:45:38 by keishii           #+#    #+#             */
/*   Updated: 2024/05/15 14:45:04 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_printf_putstr(char *s)
{
	int		len;
	char	*tmp;

	len = 0;
	if (!s)
	{
		tmp = "(null)";
		while (*tmp)
		{
			if (ft_printf_putchar(*tmp) == -1)
				return (-1);
			tmp++;
			len++;
		}
	}
	else
	{
		while (*s)
		{
			if (ft_printf_putchar(*s) == -1)
				return (-1);
			s++;
			len++;
		}
	}
	return (len);
}
