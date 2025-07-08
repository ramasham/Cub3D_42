/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:39:44 by rsham             #+#    #+#             */
/*   Updated: 2025/07/03 18:17:34 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	set_dir_north_south(t_game *game, char c)
{
	if (c == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
		game->player.plane_x = 0.66;
		game->player.plane_y = 0;
	}
	else if (c == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
		game->player.plane_x = -0.66;
		game->player.plane_y = 0;
	}
}

static void	set_dir_east_west(t_game *game, char c)
{
	if (c == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
	}
	else if (c == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = -0.66;
	}
}

static void	set_player_direction(t_game *game, char c)
{
	if (c == 'N' || c == 'S')
		set_dir_north_south(game, c);
	else if (c == 'E' || c == 'W')
		set_dir_east_west(game, c);
}

int	find_player_position(t_game *game)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (game->map.map_2d[y][x])
		{
			c = game->map.map_2d[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				game->player.x = (x + 0.5) * TILE_SIZE;
				game->player.y = (y + 0.5) * TILE_SIZE;
				set_player_direction(game, c);
				game->map.map_2d[y][x] = '0';
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
