/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:48:56 by rsham             #+#    #+#             */
/*   Updated: 2025/04/14 15:20:02 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*new_s;

	i = 0;
	if (!s)
	{
		write(2, "no string to duplicate\n", 23);
		return (NULL);
	}
	while (s[i])
		i++;
	new_s = (char *)malloc(i + 1);
	if (!new_s)
	{
		write(2, "memory allocation for new string failed\n", 40);
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
