/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keishii <keishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:57:10 by keishii           #+#    #+#             */
/*   Updated: 2024/05/16 13:39:30 by keishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "so_long.h"

int	ft_printf(const char *format, ...);
int	ft_printf_putchar(int c);
int	ft_printf_putstr(char *s);
int	ft_printf_putptr(unsigned int p);
int	ft_printf_putuint(unsigned int n);
int	ft_printf_puthex(unsigned int n, char format);

#endif
