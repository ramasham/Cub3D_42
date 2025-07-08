/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:12:27 by rsham             #+#    #+#             */
/*   Updated: 2025/07/07 12:14:51 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	**duplicate_map(char **map, int rows)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (rows + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < rows - 1)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

int	flood_fill(char **map, int x, int y, int rows)
{
	if (y < 0 || y >= rows || x < 0 || map[y] == NULL
		|| x >= (int)ft_strlen(map[y]))
		return (1);
	if (map[y][x] == ' ' || map[y][x] == '\0')
		return (1);
	if (map[y][x] == '1' || map[y][x] == 'F')
		return (0);
	map[y][x] = 'F';
	if (flood_fill(map, x + 1, y, rows))
		return (1);
	if (flood_fill(map, x - 1, y, rows))
		return (1);
	if (flood_fill(map, x, y + 1, rows))
		return (1);
	if (flood_fill(map, x, y - 1, rows))
		return (1);
	return (0);
}

static int	handle_map_error(t_game *game, char **map)
{
	free_copy_map(map);
	free_identifiers(game);
	free_map_2d(game);
	return (1);
}

int	validate_map(t_game *game)
{
	char	**copy_map;
	int		px;
	int		py;

	copy_map = duplicate_map(game->map.map_2d, game->rows);
	if (!copy_map)
		return (1);
	px = (int)(game->player.x / TILE_SIZE);
	py = (int)(game->player.y / TILE_SIZE);
	if (flood_fill(copy_map, px, py, game->rows))
	{
		ft_putstr_fd("Error: Map is not closed by walls\n", 2);
		return (handle_map_error(game, copy_map));
	}
	if (is_player_surrounded(game->map.map_2d, px, py))
	{
		ft_putstr_fd("Error: Player is surrounded by walls and cannot move!\n",
			2);
		return (handle_map_error(game, copy_map));
	}
	free_copy_map(copy_map);
	return (0);
}

int	validate_player(t_game *game)
{
	if (check_player_count(game->map.map_2d) == 0)
	{
		find_player_position(game);
		return (0);
	}
	free_identifiers(game);
	free_map_2d(game);
	ft_putstr_fd("Error: Must have exactly one player\n", 2);
	return (1);
}
