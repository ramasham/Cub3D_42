/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:41:53 by rsham             #+#    #+#             */
/*   Updated: 2025/04/16 14:14:43 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_num(int n, char format)
{
	long	i;
	int		count;

	i = n;
	count = 0;
	if (i == 0)
	{
		count += ft_print_char('0');
		return (count);
	}
	if (format == 'd' || format == 'i')
	{
		if (i < 0)
		{
			count += ft_print_char('-');
			i = -i;
		}
	}
	if (i >= 10)
		count += ft_print_num(i / 10, format);
	count += ft_print_char((i % 10) + '0');
	return (count);
}

int	ft_print_str(char *c)
{
	int	i;

	i = 0;
	if (c == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}
