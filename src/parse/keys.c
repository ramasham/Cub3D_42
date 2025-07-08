/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:40:25 by rsham             #+#    #+#             */
/*   Updated: 2025/07/07 14:31:57 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	update_position(int key, t_game *g, double *nx, double *ny)
{
	if (key == 'w')
	{
		*nx += g->player.dir_x * MOVE_SPEED;
		*ny += g->player.dir_y * MOVE_SPEED;
	}
	else if (key == 's')
	{
		*nx -= g->player.dir_x * MOVE_SPEED;
		*ny -= g->player.dir_y * MOVE_SPEED;
	}
	else if (key == 'a')
	{
		*nx += g->player.dir_y * MOVE_SPEED;
		*ny -= g->player.dir_x * MOVE_SPEED;
	}
	else if (key == 'd')
	{
		*nx -= g->player.dir_y * MOVE_SPEED;
		*ny += g->player.dir_x * MOVE_SPEED;
	}
}

static void	apply_rotation(int key, t_player *p)
{
	if (key == KEY_LEFT_ARROW)
		rotate_player(p, -ROT_SPEED);
	else if (key == KEY_RIGHT_ARROW)
		rotate_player(p, ROT_SPEED);
}

static int	check_collision(t_game *g, double x, double y)
{
	int	buffer;
	int	left;
	int	right;
	int	top;
	int	bottom;

	buffer = TILE_SIZE / 2;
	left = (int)((x - buffer) / TILE_SIZE);
	right = (int)((x + buffer) / TILE_SIZE);
	top = (int)((y - buffer) / TILE_SIZE);
	bottom = (int)((y + buffer) / TILE_SIZE);
	if (left < 0 || right >= g->cols || top < 0 || bottom >= g->rows)
		return (1);
	if (g->map.map_2d[top][left] == '1' ||
		g->map.map_2d[top][right] == '1' ||
		g->map.map_2d[bottom][left] == '1' ||
		g->map.map_2d[bottom][right] == '1')
		return (1);
	return (0);
}

int	key_handler(int key, t_game *g)
{
	double	nx;
	double	ny;

	nx = g->player.x;
	ny = g->player.y;
	update_position(key, g, &nx, &ny);
	apply_rotation(key, &g->player);
	if (!check_collision(g, nx, ny))
	{
		g->player.x = nx;
		g->player.y = ny;
	}
	return (0);
}

int	mouse_handler(int x, int y, t_game *game)
{
	int		delta_x;
	double	rotation_angle;

	if (!game->mouse_captured)
	{
		game->last_mouse_x = x;
		game->mouse_captured = 1;
		return (0);
	}
	game->mouse_x = x;
	game->mouse_y = y;
	delta_x = x - game->last_mouse_x;
	rotation_angle = delta_x * MOUSE_SENSITIVITY;
	if (rotation_angle != 0)
		rotate_player(&game->player, rotation_angle);
	game->last_mouse_x = x;
	return (0);
}
