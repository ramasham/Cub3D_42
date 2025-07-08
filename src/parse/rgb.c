/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:34:10 by rsham             #+#    #+#             */
/*   Updated: 2025/07/05 12:52:05 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	count_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	validate_rgb_values(int r, int g, int b)
{
	if (r < 0 || r > 255)
		return (0);
	if (g < 0 || g > 255)
		return (0);
	if (b < 0 || b > 255)
		return (0);
	return (1);
}

int	parse_rgb(char *line)
{
	char	**split;
	int		rgb[3];

	while (*line == 'F' || *line == 'C' || *line == ' ')
		line++;
	split = ft_split(line, ',');
	if (!split || count_split(split) != 3)
	{
		free_split(split);
		ft_putstr_fd("Error: Invalid RGB format\n", 2);
		return (-1);
	}
	rgb[0] = ft_atoi(split[0]);
	rgb[1] = ft_atoi(split[1]);
	rgb[2] = ft_atoi(split[2]);
	if (!validate_rgb_values(rgb[0], rgb[1], rgb[2]))
	{
		free_split(split);
		ft_putstr_fd("Error: RGB values must be between 0 and 255\n", 2);
		return (-1);
	}
	free_split(split);
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}
