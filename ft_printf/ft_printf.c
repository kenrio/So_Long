/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:59:26 by keishii           #+#    #+#             */
/*   Updated: 2024/05/16 15:10:40 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_format(va_list ap, const char *format, int count);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	count = check_format(ap, format, count);
	va_end(ap);
	return (count);
}

static int	check_format(va_list ap, const char *format, int count)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				count += ft_printf_putchar(va_arg(ap, int));
			else if (*format == 's')
				count += ft_printf_putstr(va_arg(ap, char *));
			else if (*format == 'p')
				count += ft_printf_putptr(va_arg(ap, unsigned int));
			else if (*format == 'u')
				count += ft_printf_putuint(va_arg(ap, unsigned int));
			else if (*format == 'x' || *format == 'X')
				count += ft_printf_puthex(va_arg(ap, int), *format);
			else if (*format == '%')
				count += ft_printf_putchar('%');
		}
		else
			count += ft_printf_putchar(*format);
		format++;
	}
	return (count);
}
