/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:34:07 by rsham             #+#    #+#             */
/*   Updated: 2025/01/21 17:40:57 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_print_char(char c);
int	ft_print_str(char *c);
int	ft_print_num(int n, char format);
int	ft_print_ptr(unsigned long n);
int	ft_print_hex(unsigned int n, char format);
int	ft_print_hex_ptr(size_t n);
int	ft_print_percent(void);
int	ft_printf(const char *str, ...);

#endif
