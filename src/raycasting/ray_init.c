/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsham <rsham@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:48:25 by rsham             #+#    #+#             */
/*   Updated: 2025/07/06 17:52:09 by rsham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_ray(t_ray *ray, t_game *game, int x)
{
	double	camera_x;
	double	player_map_x;
	double	player_map_y;

	player_map_x = game->player.x / TILE_SIZE;
	player_map_y = game->player.y / TILE_SIZE;
	camera_x = 2 * x / (double)game->screen_width - 1;
	ray->ray_dir_x = game->player.dir_x + game->player.plane_x * camera_x;
	ray->ray_dir_y = game->player.dir_y + game->player.plane_y * camera_x;
	ray->map_x = (int)player_map_x;
	ray->map_y = (int)player_map_y;
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

void	setup_dda(t_ray *ray, double player_map_x, double player_map_y)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player_map_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player_map_x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player_map_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player_map_y)
			* ray->delta_dist_y;
	}
}

static int	check_ray_bounds(t_ray *ray, t_game *game)
{
	if (ray->map_x < 0 || ray->map_x >= game->cols || ray->map_y < 0
		|| ray->map_y >= game->rows)
	{
		ray->perp_wall_dist = 1000.0;
		return (1);
	}
	return (0);
}

int	perform_dda(t_ray *ray, t_game *game)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (check_ray_bounds(ray, game))
			return (0);
		if (game->map.map_2d[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
	return (1);
}

void	calculate_projection(t_game *game, t_ray *ray, double player_map_x,
		double player_map_y)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - player_map_x + (1 - ray->step_x)
				/ 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - player_map_y + (1 - ray->step_y)
				/ 2) / ray->ray_dir_y;
	ray->line_height = (int)(game->screen_height / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + game->screen_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + game->screen_height / 2;
	if (ray->draw_end >= game->screen_height)
		ray->draw_end = game->screen_height - 1;
}
