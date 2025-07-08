/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:14:40 by rsham             #+#    #+#             */
/*   Updated: 2025/07/06 19:21:39 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (0);
	return (1);
}

int	check_player_count(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_player(map[i][j]) == 0)
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (1);
	return (0);
}

int	is_player_surrounded(char **map, int px, int py)
{
	if (py <= 0 || map[py + 1] == NULL || px <= 0 || px
		+ 1 >= (int)ft_strlen(map[py]))
		return (0);
	if (map[py - 1][px] == '1' && map[py + 1][px] == '1' && map[py][px
		- 1] == '1' && map[py][px + 1] == '1')
		return (1);
	return (0);
}
