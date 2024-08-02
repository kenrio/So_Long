/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:45:38 by keishii           #+#    #+#             */
/*   Updated: 2024/08/02 11:43:36 by keishii          ###   ########.fr       */
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
		while (tmp[len] != '\0')
		{
			if (ft_printf_putchar(tmp[len]) == -1)
				return (-1);
			len++;
		}
	}
	else
	{
		while (s[len] != '\0')
		{
			if (ft_printf_putchar(s[len]) == -1)
				return (-1);
			len++;
		}
	}
	return (len);
}
