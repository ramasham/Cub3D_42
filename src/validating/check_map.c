/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 12:27:48 by rsham             #+#    #+#             */
/*   Updated: 2025/07/05 13:12:42 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_name(char *map_name)
{
	size_t	len;

	len = ft_strlen(map_name);
	if (len < 4 || ft_strncmp(map_name + len - 4, ".cub", 4) != 0)
	{
		ft_putstr_fd("Error: Invalid map extension\n", 2);
		return (1);
	}
	return (0);
}

int	valid_map_char(char c)
{
	if (c == '1' || c == 'N' || c == '0' || c == 'S' || c == 'E' || c == 'W'
		|| c == '\t' || c == '\n' || c == ' ')
	{
		return (0);
	}
	return (1);
}

int	validate_characters(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (valid_map_char(map[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_valid_cell(char **map)
{
	if (validate_characters(map))
	{
		printf("Error: Invalid character in map\n");
		return (1);
	}
	return (0);
}
