/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:32:08 by rsham             #+#    #+#             */
/*   Updated: 2025/01/20 19:38:27 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(const char c, va_list format)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_print_char(va_arg(format, int));
	else if (c == 's')
		count = ft_print_str(va_arg(format, char *));
	else if (c == 'd' || c == 'i' || c == 'u')
		count = ft_print_num(va_arg(format, int), c);
	else if (c == 'p')
		count = ft_print_ptr(va_arg(format, unsigned long));
	else if (c == 'x' || c == 'X')
		count = ft_print_hex(va_arg(format, unsigned int), c);
	else if (c == '%')
		count = ft_print_percent();
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		c;
	int		i;

	c = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			c += ft_print_char(str[i++]);
		else
		{
			c += ft_format(str[i + 1], args);
			i += 2;
		}
	}
	va_end(args);
	return (c);
}
